#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
class Player
{
    public:
    Player (const char* name, int m_force = 5, int m_maxHP = 100);
    Player (const Player& playerToCopy);
    Player () = default;
    ~Player() = default; // check if ok
    void printInfo();
    void levelUp();
    int getLevel();
    void buff(int forceToAdd);
    void heal(int HPToAdd);
    void damage(int HPToTake);
    bool isKnockedOut();
    void addCoins(int coinsToAdd);
    bool pay(int price);
    int getAttackStrength();

    Player& operator=(const Player& otherPlayer)
    {
      if (this == &otherPlayer)
      {
        return *this;
      }

      m_level = otherPlayer.m_level;
      m_force = otherPlayer.m_force;
      m_maxHP = otherPlayer.m_maxHP;
      m_HP = otherPlayer.m_HP;
      m_coins = otherPlayer.m_coins;

      return *this;
      
    }

    private:
    std::string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;
    // assignment!
//Set& Set::operator=(const Set& s)
//{
  //  if(rhi)
//}

};
#endif // PLAYER_H