/*  Copyright 2012 MaidSafe.net limited

    This MaidSafe Software is licensed to you under (1) the MaidSafe.net Commercial License,
    version 1.0 or later, or (2) The General Public License (GPL), version 3, depending on which
    licence you accepted on initial access to the Software (the "Licences").

    By contributing code to the MaidSafe Software, or to this project generally, you agree to be
    bound by the terms of the MaidSafe Contributor Agreement, version 1.0, found in the root
    directory of this project at LICENSE, COPYING and CONTRIBUTOR respectively and also
    available at: http://www.maidsafe.net/licenses

    Unless required by applicable law or agreed to in writing, the MaidSafe Software distributed
    under the GPL Licence is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS
    OF ANY KIND, either express or implied.

    See the Licences for the specific language governing permissions and limitations relating to
    use of the MaidSafe Software.                                                                 */

#include "maidsafe/vault/tests/vault_network.h"

#include <algorithm>

#include "maidsafe/common/test.h"
#include "maidsafe/vault/tests/tests_utils.h"

namespace maidsafe {

namespace vault {

namespace test {

class VaultNetworkTest : public VaultNetwork  {
 public:
  VaultNetworkTest() {}
};

TEST_F(VaultNetworkTest, FUNC_BasicSetup) {
}

TEST_F(VaultNetworkTest, FUNC_ClientJoins) {
  EXPECT_TRUE(AddClient(false));
}

TEST_F(VaultNetworkTest, FUNC_RegisteringPmidClientJoins) {
  EXPECT_TRUE(AddClient(true));
}

TEST_F(VaultNetworkTest, FUNC_MultipleClientsJoin) {
  for (int index(0); index < 5; ++index)
    EXPECT_TRUE(AddClient(false));
}

TEST_F(VaultNetworkTest, FUNC_StoreLoadDelete) {
  EXPECT_TRUE(AddClient());
  ImmutableData data(NonEmptyString(RandomString(1024)));
  clients_[0]->nfs_->Put(data);
  Sleep(std::chrono::seconds(2));
  auto future(clients_[0]->nfs_->Get<ImmutableData::Name>(data.name(), std::chrono::seconds(5)));
  try {
    auto retrieved(future.get());
    EXPECT_EQ(retrieved.data(), data.data());
  }
  catch (...) {
    EXPECT_TRUE(false) << "Failed to retrieve: " << DebugId(NodeId(data.name()->string()));
  }
}

}  // namespace test

}  // namespace vault

}  // namespace maidsafe

