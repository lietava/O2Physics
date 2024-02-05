// Copyright 2019-2020 CERN and copyright holders of ALICE O2.
// See https://alice-o2.web.cern.ch/copyright for details of the copyright holders.
// All rights not expressly granted are reserved.
//
// This software is distributed under the terms of the GNU General Public
// License v3 (GPL Version 3), copied verbatim in the file "COPYING".
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

#include <catch_amalgamated.hpp>
#include "Headers/DataHeader.h"
#include "Framework/DataOutputDirector.h"
#include <fstream>

TEST_CASE("TestDataOutputDirector")
{
  using namespace o2::header;
  using namespace o2::framework;

  DataOutputDirector dod;
  auto dh = DataHeader(DataDescription{"UNO"},
                       DataOrigin{"AOD"},
                       DataHeader::SubSpecificationType{0});
  std::string mydfn("myresultfile");

  // test keepString reader
  std::string keepString("AOD/UNO/0:tr1:c1/c2/c3:fn1,AOD/UNO/0::c4");
  dod.readString(keepString);
  dod.setFilenameBase(mydfn);

  auto ds = dod.getDataOutputDescriptors(dh);

  REQUIRE(ds.size() == 2);

  REQUIRE(ds[0]->tablename == std::string("UNO"));
  REQUIRE(ds[0]->treename == std::string("tr1"));
  REQUIRE(ds[0]->colnames.size() == 3);
  REQUIRE(ds[0]->getFilenameBase() == std::string("fn1"));

  REQUIRE(ds[1]->tablename == std::string("UNO"));
  REQUIRE(ds[1]->treename == std::string("O2uno"));
  REQUIRE(ds[1]->colnames.size() == 1);
  REQUIRE(ds[1]->getFilenameBase() == std::string("myresultfile"));

  // test jsonString reader
  std::string rdn("./");
  std::string dfn("");
  std::string fmode("");
  float mfs = -1.;
  int ntf = -1;

  dh = DataHeader(DataDescription{"DUE"},
                  DataOrigin{"AOD"},
                  DataHeader::SubSpecificationType{0});
  std::string jsonString(R"({"OutputDirector": {"resfile": "defresults", "resfilemode": "RECREATE", "ntfmerge": 10, "OutputDescriptors": [{"table": "AOD/UNO/0", "columns": ["fEta1","fMom1"], "treename": "uno", "filename": "unoresults"}, {"table": "AOD/DUE/0", "columns": ["fPhi2"], "treename": "due"}]}})");

  dod.reset();
  std::tie(rdn, dfn, fmode, mfs, ntf) = dod.readJsonString(jsonString);
  ds = dod.getDataOutputDescriptors(dh);

  REQUIRE(ds.size() == 1);
  REQUIRE(dfn == std::string("defresults"));
  REQUIRE(fmode == std::string("RECREATE"));
  REQUIRE(ntf == 10);

  REQUIRE(ds[0]->tablename == std::string("DUE"));
  REQUIRE(ds[0]->treename == std::string("due"));
  REQUIRE(ds[0]->colnames.size() == 1);
  REQUIRE(ds[0]->getFilenameBase() == std::string("defresults"));

  // test json file reader
  std::string jsonFile("testO2config.json");
  std::ofstream jf(jsonFile, std::ofstream::out);
  jf << R"({)" << std::endl;
  jf << R"(  "OutputDirector": {)" << std::endl;
  jf << R"(    "resfile": "defresults",)" << std::endl;
  jf << R"(    "resfilemode": "NEW",)" << std::endl;
  jf << R"(    "ntfmerge": 10,)" << std::endl;
  jf << R"(    "OutputDescriptors": [)" << std::endl;
  jf << R"(      {)" << std::endl;
  jf << R"(        "table": "AOD/DUE/0",)" << std::endl;
  jf << R"(        "columns": [)" << std::endl;
  jf << R"(          "fEta1",)" << std::endl;
  jf << R"(          "fMom1")" << std::endl;
  jf << R"(        ],)" << std::endl;
  jf << R"(        "treename": "uno",)" << std::endl;
  jf << R"(        "filename": "unoresults")" << std::endl;
  jf << R"(      },)" << std::endl;
  jf << R"(      {)" << std::endl;
  jf << R"(        "table": "AOD/DUE/0",)" << std::endl;
  jf << R"(        "columns": [)" << std::endl;
  jf << R"(          "fPhi2")" << std::endl;
  jf << R"(        ],)" << std::endl;
  jf << R"(        "treename": "due",)" << std::endl;
  jf << R"(        "filename": "dueresults")" << std::endl;
  jf << R"(      })" << std::endl;
  jf << R"(    ])" << std::endl;
  jf << R"(  })" << std::endl;
  jf << R"(})" << std::endl;
  jf.close();

  dod.reset();
  std::tie(rdn, dfn, fmode, mfs, ntf) = dod.readJson(jsonFile);
  dod.setFilenameBase("AnalysisResults");
  ds = dod.getDataOutputDescriptors(dh);

  REQUIRE(ds.size() == 2);
  REQUIRE(dfn == std::string("defresults"));
  REQUIRE(fmode == std::string("NEW"));
  REQUIRE(ntf == 10);

  REQUIRE(ds[0]->getFilenameBase() == std::string("unoresults"));
  REQUIRE(ds[0]->tablename == std::string("DUE"));
  REQUIRE(ds[0]->treename == std::string("uno"));
  REQUIRE(ds[0]->colnames.size() == 2);

  REQUIRE(ds[1]->getFilenameBase() == std::string("dueresults"));
  REQUIRE(ds[1]->tablename == std::string("DUE"));
  REQUIRE(ds[1]->treename == std::string("due"));
  REQUIRE(ds[1]->colnames.size() == 1);
}