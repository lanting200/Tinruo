#pragma once

#include <algorithm>
#include <array>
#include <cstddef>
#include <iterator>
#include <span>
#include <variant>

#include <SDK/Constants/ProPlayer.h>
#include <SDK/Constants/TournamentTeam.h>
#include <SDK/ItemSchema.h>

namespace inventory_changer
{
    enum class TournamentMap : std::uint8_t;
}

namespace inventory_changer::item_generator
{

struct MatchWithMVPs {
    TournamentMap map;
    TournamentStage stage;
    TournamentTeam team1;
    TournamentTeam team2;
    std::array<csgo::ProPlayer, 10> mvpPlayers;
};

[[nodiscard]] constexpr std::size_t countMVPs(const MatchWithMVPs& matchWithMVPs)
{
    return static_cast<std::size_t>(std::distance(matchWithMVPs.mvpPlayers.begin(), std::ranges::find(matchWithMVPs.mvpPlayers, csgo::ProPlayer{})));
}

struct Match {
    TournamentMap map;
    TournamentStage stage;
    TournamentTeam team1;
    TournamentTeam team2;
};

[[nodiscard]] std::variant<std::span<const MatchWithMVPs>, std::span<const Match>> getTournamentMatchesOnMap(std::uint32_t tournamentID, TournamentMap map) noexcept;

}
