#include "utilities.h"
#include "Card.h"
#include <string>
#include <iostream>
using std::cout;
using std::endl;

/*
* C'tor of Card class
*
* @param type - The type of the card.
* @param stats - The numeral stats of the card.
* @return
*      A new instance of Card.
*/
Card::Card(CardType type, const CardStats& stats)
{
    this->m_stats = stats; // I think it should maybe be different
    this->m_effect = type;
}

/*
* Handling the player's applyEncounter with the card:
*
* @param player - The player.
* @return
*      void
*/

void Card:: applyEncounter(Player& player) const
{
    if (this->m_effect == CardType::Battle)
    {
        if(player.getAttackStrength() >= this->m_stats.force)
        {
            player.levelUp();
            player.addCoins(this->m_stats.loot);
            printBattleResult(true);
        }
        else
        {
            player.damage(this->m_stats.hpLossOnDefeat);
            printBattleResult(false);
        }
        
    }

    if (this->m_effect == CardType::Buff)
    {
        bool purchesd = player.pay(this->m_stats.cost);
        if (purchesd)
        {
            player.buff(this->m_stats.buff);
        }
    }

    if (this->m_effect == CardType::Heal)
    {
        bool purchesd = player.pay(this->m_stats.cost);
        if (purchesd)
        {
            player.heal(this->m_stats.heal);
        }
    }

    if (this->m_effect == CardType::Treasure)
    {
        player.addCoins(this->m_stats.loot);
    }
}

/*
 * Prints the card info:
 *
 * @return
 *      void
 */
void Card:: printInfo() const
{
    switch (this->m_effect)
    {
        case CardType::Battle:
            printBattleCardInfo(this->m_stats);
        case CardType::Buff:
            printBuffCardInfo(this->m_stats);
        case CardType::Heal:
            printHealCardInfo(this->m_stats);
        case CardType::Treasure:
            printTreasureCardInfo(this->m_stats);

    }
}