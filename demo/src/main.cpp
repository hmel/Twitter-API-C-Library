#include <iostream>
#include <twitterlib/tal.hpp>

int main() {
    tal::App app{"flxndnoaoOxzseVrt1dx61iZx",
                 "HdSCNMhaWQAWUswvEymQqC11p0nVSpf1qvZykUYe5jdgYYchHU"};
    tal::Account account{"838185577975533571-2PXBkay7faR0b3lT7f3K2fKX2t7CAe3",
                         "UC3HtOyZuGSFHZR7JD2tSKMHRoaSVZ8AWPQONEjXku5Rn"};

    app.set_account(account);

    auto results = app.get_favorites("BarackObama", 3);
    for (const auto& tweet : results) {
        std::cout << tweet << "\n- - - - - - - - -" << std::endl;
    }

    // for (const auto& id : app.get_blocked_users()) {
    //     std::cout << id << '\n';
    // }
    // auto vec_users = app.get_blocked_users();
    // std::cout << vec_users.at(0).status << std::endl;
    // std::cout << app.get_account_rate_limit_status() << std::endl;

    // app.get_collection("custom-539487832448843776");
    // std::cout << app.find_collections("npr");

    return 0;
}