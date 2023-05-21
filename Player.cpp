#include "utilities.h"
#include "Player.h"
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;



/* @param: name: name of new player
 * @param: force: force for new player (if not received then default is 5)
 * @param: maxHP: starting hp for new player (if not received then default is 100)
 *
 * c'tor for player, making a new player according to the input given
 */
Player::Player(const char *name, int force, int maxHP)
{
    const std::string playerName = std::string(name);
    this->m_name = playerName;
    this->m_force = force;
    this->m_HP = maxHP;
    this->m_maxHP = maxHP;
    this->m_coins = 0;
    this->m_level = 1;
}

/* @param: playerToCopy: player To Copy
 *
 *  copy c'tor for player, making a new player according to the input given
 */
Player::Player(const Player& playerToCopy)
{
    const std::string playerName = playerToCopy.m_name;
    this->m_name = playerName;
    m_force = playerToCopy.m_force;
    m_level = playerToCopy.m_level;
    m_HP = playerToCopy.m_HP;
    m_maxHP = playerToCopy.m_maxHP;
    m_coins = playerToCopy.m_coins;
}

/* d'tor for player */
//Player::~Player()
////{
 //   delete[]// m_name;
//}


/*printInfo prints all the uniqe information the player posses */
void Player:: printInfo()
{
    const char* nameInChar = this->m_name.c_str();
    printPlayerInfo(nameInChar, this->m_level, this->m_force, this->m_HP, this->m_coins);
    return;
}

/*upgrades the players level by 1 */
void Player:: levelUp()
{
    if (this->m_level == 10)
    {
        return;
    }
    this->m_level ++;
    return;
}

/*getLevel returns players current level */
int Player:: getLevel()
{
    return this->m_level;
}

/*@param: forceToAdd: amount of force to add
*
* buff adds force points according to the input */
void Player:: buff(int forceToAdd)
{
    this->m_force += forceToAdd;
}

/*@param: HPToAdd: amount of HP to add
*
* heal adds healing points according to the input */
void Player:: heal(int HPToAdd)
{
    if (HPToAdd < 0)
    {
        return;
    }
    this->m_HP += HPToAdd;
    if (this->m_HP > this->m_maxHP)
    {
        this->m_HP = this->m_maxHP;
    }
    return;
}

/*@param: HPToTake: amount of HP to deduct
*
* removes healing points according to the input */
void Player:: damage(int HPToTake)
{
    if (HPToTake < 0)
    {
        return;
    }
    this->m_HP = this->m_HP - HPToTake;
    if (this->m_HP < 0)
    {
        this->m_HP = 0;
    }
    return;
}

/* isKnockedOut checks if the players HP is at 0
* return true if the are*/
bool Player:: isKnockedOut()
{
    if (this->m_HP ==0)
    {
        return true;
    }
    return false;
}

/*@param: addCoins: amount of coins to add
*
* heal adds coins according to the input */
void Player:: addCoins(int coinsToAdd)
{
    this->m_coins += coinsToAdd;
}

/*@param: price: amount of coins needed for transaction
*
* pay function attemps to make a purches with the players coins
* if the players has enough coins the function allows the purches,
* deducts the price from the players coins and returns true
* 
*if player doesn't have enough coins the fuctions won't 
*deduct coins and will return false*/
bool Player:: pay(int price)
{
    if (this->m_coins < price)
    {
        return false;
    }
    this->m_coins -= price;
    return true;
}

/*getAttackStrength returns players current strength
* calculated by the sum of his kevek and his force */
int Player:: getAttackStrength()
{
    return this->m_force + this->m_level;
}