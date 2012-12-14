/***************************************************************************************************
 *  Copyright 2012 MaidSafe.net limited                                                            *
 *                                                                                                 *
 *  The following source code is property of MaidSafe.net limited and is not meant for external    *
 *  use.  The use of this code is governed by the licence file licence.txt found in the root of    *
 *  this directory and also on www.maidsafe.net.                                                   *
 *                                                                                                 *
 *  You are not free to copy, amend or otherwise use this source code without the explicit         *
 *  written permission of the board of directors of MaidSafe.net.                                  *
 **************************************************************************************************/

#ifndef MAIDSAFE_VAULT_DEMULTIPLEXER_H_
#define MAIDSAFE_VAULT_DEMULTIPLEXER_H_

#include <string>

namespace maidsafe {

namespace vault {

class Demultiplexer {
 public:
  Demultiplexer(DataHolder& data_holder,
                MaidAccountHolder& maid_account_holder,
                MetadataManager& metadata_manager,
                PmidAccountHolder& pmid_account_holder);
  void HandleMessage(const std::string& message);

 private:
  DataHolder& data_holder_;
  MaidAccountHolder& maid_account_holder_;
  MetadataManager& metadata_manager_;
  PmidAccountHolder& mpid_account_holder_;
};

}  // namespace vault

}  // namespace maidsafe

#endif  // MAIDSAFE_VAULT_DEMULTIPLEXER_H_
