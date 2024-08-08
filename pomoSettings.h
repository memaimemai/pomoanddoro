#ifndef POMO_SETTINGS_H
#define POMO_SETTINGS_H
#pragma once
#include <iostream>
#include <fstream>
#include <string>

    class pomoSettings {
public:
  pomoSettings();
  ~pomoSettings();
  int getAnswerAmount();
  int getAnswerMinutes();
  int getPomo();
  void setPomo(int newPomo);
  int getAmount();
  void setAmount(int newAmount);
  int getShortbreak();
  void setShortbreak(int newShortbreak);
  int getLongbreak();
  void setLongbreak(int newLongBreak);
  void setDefault();
private:
  std::fstream myfile;
  int t_Shortbreak;
  int t_Longbreak;
  int t_Pomo;
  int t_Amount;

  void initSettings();
  void writeSettings();
};
#endif
