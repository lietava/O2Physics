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

/// \file PhysicsConstants.h
/// \brief Header to collect physics constants
/// \author ruben.shahoyan@cern.ch
/// \author Vít Kučera <vit.kucera@cern.ch>, Inha University
/// \note Use the make_pdg_header.py script to generate the enums and mass declarations.

#ifndef ALICEO2_PHYSICSCONSTANTS_H_
#define ALICEO2_PHYSICSCONSTANTS_H_

namespace o2::constants::physics
{
// particles masses

// BEGINNING OF THE GENERATED BLOCK.
// DO NOT EDIT THIS BLOCK DIRECTLY!
// It has been generated by the make_pdg_header.py script.
// For modifications, edit the script and generate this block again.

/// \brief Declarations of named PDG codes of particles missing in ROOT PDG_t
/// \note Follow kCamelCase naming convention
/// \link https://root.cern/doc/master/TPDGCode_8h.html
enum Pdg {
  kB0 = 511,
  kB0Bar = -511,
  kBPlus = 521,
  kBS = 531,
  kBSBar = -531,
  kD0 = 421,
  kD0Bar = -421,
  kDMinus = -411,
  kDPlus = 411,
  kDS = 431,
  kDSBar = -431,
  kDStar = 413,
  kChiC1 = 20443,
  kJPsi = 443,
  kLambdaB0 = 5122,
  kLambdaCPlus = 4122,
  kOmegaC0 = 4332,
  kPhi = 333,
  kSigmaC0 = 4112,
  kSigmaCPlusPlus = 4222,
  kX3872 = 9920443,
  kXi0 = 3322,
  kXiB0 = 5232,
  kXiCCPlusPlus = 4422,
  kXiCPlus = 4232,
  kXiC0 = 4132,
  kDeuteron = 1000010020,
  kTriton = 1000010030,
  kHelium3 = 1000020030,
  kAlpha = 1000020040,
  kHyperTriton = 1010010030,
  kHyperHydrogen4 = 1010010040,
  kHyperHelium4 = 1010020040
};

/// \brief Declarations of masses for additional particles
constexpr double MassB0 = 5.27966;
constexpr double MassB0Bar = 5.27966;
constexpr double MassBPlus = 5.27934;
constexpr double MassBS = 5.36692;
constexpr double MassBSBar = 5.36692;
constexpr double MassD0 = 1.86484;
constexpr double MassD0Bar = 1.86484;
constexpr double MassDMinus = 1.86966;
constexpr double MassDPlus = 1.86966;
constexpr double MassDS = 1.96835;
constexpr double MassDSBar = 1.96835;
constexpr double MassDStar = 2.01026;
constexpr double MassChiC1 = 3.51067;
constexpr double MassJPsi = 3.0969;
constexpr double MassLambdaB0 = 5.6196;
constexpr double MassLambdaCPlus = 2.28646;
constexpr double MassOmegaC0 = 2.6952;
constexpr double MassPhi = 1.019461;
constexpr double MassSigmaC0 = 2.45375;
constexpr double MassSigmaCPlusPlus = 2.45397;
constexpr double MassX3872 = 3.87165;
constexpr double MassXi0 = 1.31486;
constexpr double MassXiB0 = 5.7919;
constexpr double MassXiCCPlusPlus = 3.62155;
constexpr double MassXiCPlus = 2.46771;
constexpr double MassXiC0 = 2.47044;
constexpr double MassDeuteron = 1.87561294257;
constexpr double MassTriton = 2.80892113298;
constexpr double MassHelium3 = 2.80839160743;
constexpr double MassAlpha = 3.7273794066;
constexpr double MassHyperTriton = 2.99131;
constexpr double MassHyperHydrogen4 = 3.9226;
constexpr double MassHyperHelium4 = 3.9217;

/// \brief Declarations of masses for particles in ROOT PDG_t
constexpr double MassDown = 0.00467;
constexpr double MassDownBar = 0.00467;
constexpr double MassUp = 0.00216;
constexpr double MassUpBar = 0.00216;
constexpr double MassStrange = 0.0934;
constexpr double MassStrangeBar = 0.0934;
constexpr double MassCharm = 1.27;
constexpr double MassCharmBar = 1.27;
constexpr double MassBottom = 4.18;
constexpr double MassBottomBar = 4.18;
constexpr double MassTop = 172.5;
constexpr double MassTopBar = 172.5;
constexpr double MassGluon = 0.0;
constexpr double MassElectron = 0.000510999;
constexpr double MassPositron = 0.000510999;
constexpr double MassNuE = 0.0;
constexpr double MassNuEBar = 0.0;
constexpr double MassMuonMinus = 0.1056584;
constexpr double MassMuonPlus = 0.1056584;
constexpr double MassNuMu = 0.0;
constexpr double MassNuMuBar = 0.0;
constexpr double MassTauMinus = 1.77686;
constexpr double MassTauPlus = 1.77686;
constexpr double MassNuTau = 0.0;
constexpr double MassNuTauBar = 0.0;
constexpr double MassGamma = 0.0;
constexpr double MassZ0 = 91.1876;
constexpr double MassWPlus = 80.377;
constexpr double MassWMinus = 80.377;
constexpr double MassPi0 = 0.1349768;
constexpr double MassK0Long = 0.497611;
constexpr double MassPiPlus = 0.1395704;
constexpr double MassPiMinus = 0.1395704;
constexpr double MassProton = 0.9382721;
constexpr double MassProtonBar = 0.9382721;
constexpr double MassNeutron = 0.9395654;
constexpr double MassNeutronBar = 0.9395654;
constexpr double MassK0Short = 0.497611;
constexpr double MassK0 = 0.497611;
constexpr double MassK0Bar = 0.497611;
constexpr double MassKPlus = 0.493677;
constexpr double MassKMinus = 0.493677;
constexpr double MassLambda0 = 1.115683;
constexpr double MassLambda0Bar = 1.115683;
constexpr double MassLambda1520 = 1.519;
constexpr double MassSigmaMinus = 1.197449;
constexpr double MassSigmaBarPlus = 1.197449;
constexpr double MassSigmaPlus = 1.18937;
constexpr double MassSigmaBarMinus = 1.18937;
constexpr double MassSigma0 = 1.192642;
constexpr double MassSigma0Bar = 1.192642;
constexpr double MassXiMinus = 1.32171;
constexpr double MassXiPlusBar = 1.32171;
constexpr double MassOmegaMinus = 1.67245;
constexpr double MassOmegaPlusBar = 1.67245;

// END OF THE GENERATED BLOCK

// legacy names
constexpr double MassPhoton = MassGamma;
constexpr double MassMuon = MassMuonMinus;
constexpr double MassPionCharged = MassPiPlus;
constexpr double MassPionNeutral = MassPi0;
constexpr double MassKaonCharged = MassKPlus;
constexpr double MassKaonNeutral = MassK0;
constexpr double MassLambda = MassLambda0;
constexpr double MassHyperhydrog4 = MassHyperHydrogen4;
constexpr double MassHyperhelium4 = MassHyperHelium4;

constexpr float LightSpeedCm2S = 299792458.e2;           // C in cm/s
constexpr float LightSpeedCm2NS = LightSpeedCm2S * 1e-9; // C in cm/ns
} // namespace o2::constants::physics

#endif