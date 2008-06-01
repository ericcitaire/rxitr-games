// 
// This file is part of JezzballDS.
// 
// JezzballDS is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// JezzballDS is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with JezzballDS.  If not, see <http://www.gnu.org/licenses/>.
// 

#include <PA9.h>
#include "messages.h"

#include "gfx/all_gfx.h"

void initLang(l18n * messages)
  {
    switch (PA_UserInfo.Language)
      {
    case LANG_FR:
      messages->menu = &msg_menu_fr;
      messages->options = &msg_options_fr;
      messages->optionsValues = &msg_optionsValues_fr;
      messages->gameover = &msg_gameover_fr;
      messages->levelcomplete = &msg_levelcomplete_fr;
      messages->score = &msg_score_fr;
      messages->pause = &msg_pause_fr;
      messages->none = &msg_none;
      messages->title = &msg_title_fr;
      messages->about = &msg_about_fr;
      messages->highscores = &msg_highscores_fr;
      messages->newhighscore = &msg_newhighscore_fr;
      messages->update_score = &msg_update_score;
      break;
    default:
      messages->menu = &msg_menu_en;
      messages->options = &msg_options_en;
      messages->optionsValues = &msg_optionsValues_en;
      messages->gameover = &msg_gameover_en;
      messages->levelcomplete = &msg_levelcomplete_en;
      messages->score = &msg_score_en;
      messages->pause = &msg_pause_en;
      messages->none = &msg_none;
      messages->title = &msg_title_en;
      messages->about = &msg_about_en;
      messages->highscores = &msg_highscores_en;
      messages->newhighscore = &msg_newhighscore_en;
      messages->update_score = &msg_update_score;
      break;
      }
    
    PA_16cCustomFont(5, smallfont);
    PA_LoadPal16(PAL_BG1, 15, smallfont_Pal);
  }

void msg_none(void)
  {
    PA_HideBg(0, 0);
  }

void msg_gameover_en(void)
  {
    PA_ClearBg(0, 0);
    PA_EasyBgLoad(0, 0, msg_en_gameover);
    PA_ShowBg(0, 0);
  }

void msg_menu_en(void)
  {
    PA_ClearBg(0, 0);
    PA_EasyBgLoad(0, 0, msg_en_menu);
    PA_ShowBg(0, 0);
  }

void msg_menu_fr(void)
  {
    PA_ClearBg(0, 0);
    PA_EasyBgLoad(0, 0, msg_fr_menu);
    PA_ShowBg(0, 0);
  }

void msg_options_en(void)
  {
    PA_EasyBgLoad(0, 1, msg_en_options);
    
    PA_EasyBgLoad(1, 1, msg_en_title_controls);
    
    PA_Init16cBg(1, 0);
    PA_16cTextAlign(ALIGN_CENTER);
    
    PA_16cText(1, 0, 64, 255, 191,
          "A or Stylus:\n"
          "create a wall\n\n"
          "B or L / R:\n"
          "change cursor orientation\n\n"
          "X:\n"
          "create a vertical wall\n\n"
          "Y:\n"
          "create a horizontal wall\n\n"
          "D-pad:\n"
          "move cursor"
        , 1, 5, 10000);
  }

void msg_options_fr(void)
  {
    PA_EasyBgLoad(0, 1, msg_en_options);
    
    PA_EasyBgLoad(1, 1, msg_fr_title_controls);
    
    PA_Init16cBg(1, 0);
    PA_16cTextAlign(ALIGN_CENTER);
    
    PA_16cText(1, 0, 64, 255, 191,
          "A ou Stylet:\n"
          "cr�� un mur\n\n"
          "B ou L / R:\n"
          "change l'orientation du curseur\n\n"
          "X:\n"
          "cr�� un mur vertical\n\n"
          "Y:\n"
          "cr�� un mur horizontal\n\n"
          "D-pad:\n"
          "d�place le curseur"
        , 1, 5, 10000);
  }

#define displayOption(optionLabel, choicesLabels, option, y) \
  { \
    PA_16cTextAlign(ALIGN_LEFT); \
    PA_16cText(0, 16, y, 127, 191, optionLabel, 1, 5, 100); \
    PA_16cTextAlign(ALIGN_CENTER); \
    PA_16cText(0, 136, y, 231, 191, choicesLabels[option], 1, 5, 100); \
  }

void msg_optionsValues_en(u8 * options, u8 selectedOption)
  {
    char * soundfxChoicesLabels[2] = {"Yes", "No"}; 
    char * speedChoicesLabels[3] = {"Slow", "Medium", "Fast"}; 
    char * ballsChoicesLabels[2] = {"Classic", "Smiley"}; 
    char * stylusmodeChoicesLabels[2] = {"Click", "Stretch"};
    
    u8 y = 40, lineHeight = 12;
    
    PA_Init16cBg(0, 0);
    
    PA_16cTextAlign(ALIGN_CENTER);
    PA_16cText(0, 127, y + lineHeight * selectedOption, 135, 191, "<", 1, 5, 1);
    PA_16cText(0, 232, y + lineHeight * selectedOption, 239, 191, ">", 1, 5, 1);
    
    displayOption("Sound:", soundfxChoicesLabels, options[OPTION_SOUNDFX], y);
    y += lineHeight;
    displayOption("Speed:", speedChoicesLabels, options[OPTION_SPEED], y);
    y += lineHeight;
    displayOption("Balls:", ballsChoicesLabels, options[OPTION_BALLS], y);
    y += lineHeight;
    displayOption("Stylus mode:", stylusmodeChoicesLabels, options[OPTION_STYLUSMODE], y);
    y += lineHeight;
    
    PA_16cTextAlign(ALIGN_CENTER);
    PA_16cText(0, 16, 183, 231, 191, "Press A to apply or B to discard", 1, 0, 100);
  }

void msg_optionsValues_fr(u8 * options, u8 selectedOption)
  {
    char * soundfxChoicesLabels[2] = {"Oui", "Non"}; 
    char * speedChoicesLabels[3] = {"Lent", "Moyen", "Rapide"}; 
    char * ballsChoicesLabels[2] = {"Classique", "Smiley"}; 
    char * stylusmodeChoicesLabels[2] = {"Clic", "Stretch"};
    
    u8 y = 40, lineHeight = 12;
    
    PA_Init16cBg(0, 0);
    
    PA_16cTextAlign(ALIGN_CENTER);
    PA_16cText(0, 127, y + lineHeight * selectedOption, 135, 191, "<", 1, 5, 1);
    PA_16cText(0, 232, y + lineHeight * selectedOption, 239, 191, ">", 1, 5, 1);
    
    displayOption("Son:", soundfxChoicesLabels, options[OPTION_SOUNDFX], y);
    y += lineHeight;
    displayOption("Vitesse:", speedChoicesLabels, options[OPTION_SPEED], y);
    y += lineHeight;
    displayOption("Balles:", ballsChoicesLabels, options[OPTION_BALLS], y);
    y += lineHeight;
    displayOption("Mode stylet:", stylusmodeChoicesLabels, options[OPTION_STYLUSMODE], y);
    y += lineHeight;
    
    PA_16cTextAlign(ALIGN_CENTER);
    PA_16cText(0, 16, 175, 231, 191, "Appuyez sur A pour appliquer\nou sur B pour annuler", 1, 0, 100);
  }

void msg_gameover_fr(void)
  {
    PA_ClearBg(0, 0);
    PA_EasyBgLoad(0, 0, msg_fr_gameover);
    PA_ShowBg(0, 0);
  }

void msg_levelcomplete_en(void)
  {
    PA_ClearBg(0, 0);
    PA_EasyBgLoad(0, 0, msg_en_levelcomplete);
    PA_ShowBg(0, 0);
  }

void msg_levelcomplete_fr(void)
  {
    PA_ClearBg(0, 0);
    PA_EasyBgLoad(0, 0, msg_fr_levelcomplete);
    PA_ShowBg(0, 0);
  }

void msg_pause_en(void)
  {
    PA_ClearBg(0, 0);
    PA_EasyBgLoad(0, 0, msg_en_pause);
    PA_ShowBg(0, 0);
  }

void msg_pause_fr(void)
  {
    PA_ClearBg(0, 0);
    PA_EasyBgLoad(0, 0, msg_fr_pause);
    PA_ShowBg(0, 0);
  }

void msg_newhighscore_en(void)
  {
    PA_ClearBg(0, 0);
    PA_EasyBgLoad(0, 0, msg_en_newhighscore);
    PA_ShowBg(0, 0);
  }

void msg_newhighscore_fr(void)
  {
    PA_ClearBg(0, 0);
    PA_EasyBgLoad(0, 0, msg_fr_newhighscore);
    PA_ShowBg(0, 0);
  }

void msg_title_en(void)
  {
    PA_ClearBg(1, 1);
    PA_EasyBgLoad(1, 1, msg_en_title);
    PA_ShowBg(1, 1);
  }

void msg_title_fr(void)
  {
    PA_ClearBg(1, 1);
    PA_EasyBgLoad(1, 1, msg_fr_title);
    PA_ShowBg(1, 1);
  }

void msg_update_score(u8 level, u8 lives, u8 complete, s16 timeLeft, u32 score, u32 bonus)
  {
    u8 y = 80;
    u8 lineHeight = 12;
    char txt[10];
    
    PA_16cClearZone(1, 128, 0, 255, 191);
    
    PA_16cTextAlign(ALIGN_RIGHT);
    sprintf(txt, "%d", level);
    PA_16cText(1, 128, y+lineHeight*0, 239, 191, txt, 1, 5, 100);
    sprintf(txt, "%d", lives);
    PA_16cText(1, 128, y+lineHeight*1, 239, 191, txt, 1, 5, 100);
    sprintf(txt, "%d%%", complete);
    PA_16cText(1, 128, y+lineHeight*2, 239, 191, txt, 1, 5, 100);
    sprintf(txt, "%d", timeLeft);
    PA_16cText(1, 128, y+lineHeight*3, 239, 191, txt, 1, 5, 100);
    sprintf(txt, "%d", score);
    PA_16cText(1, 128, y+lineHeight*4, 239, 191, txt, 1, 5, 100);
    sprintf(txt, "%d", bonus);
    PA_16cText(1, 128, y+lineHeight*5, 239, 191, txt, 1, 5, 100);
  }

void msg_score_en(void)
  {
    u8 y = 80;
    u8 lineHeight = 12;
    
    PA_Init16cBg(1, 0);
    
    PA_16cTextAlign(ALIGN_LEFT);
    PA_16cText(1, 16, y+lineHeight*0, 127, 191, "Level:", 1, 5, 100);
    PA_16cText(1, 16, y+lineHeight*1, 127, 191, "Lives:", 1, 5, 100);
    PA_16cText(1, 16, y+lineHeight*2, 127, 191, "Area cleared:", 1, 5, 100);
    PA_16cText(1, 16, y+lineHeight*3, 127, 191, "Time left:", 1, 5, 100);
    PA_16cText(1, 16, y+lineHeight*4, 127, 191, "Score:", 1, 5, 100);
    PA_16cText(1, 16, y+lineHeight*5, 127, 191, "Bonus:", 1, 5, 100);
  }

void msg_score_fr(void)
  {
    u8 y = 80;
    u8 lineHeight = 12;
    
    PA_Init16cBg(1, 0);
    
    PA_16cTextAlign(ALIGN_LEFT);
    PA_16cText(1, 16, y+lineHeight*0, 127, 191, "Niveau:", 1, 5, 100);
    PA_16cText(1, 16, y+lineHeight*1, 127, 191, "Vies:", 1, 5, 100);
    PA_16cText(1, 16, y+lineHeight*2, 127, 191, "Zone nettoy�e:", 1, 5, 100);
    PA_16cText(1, 16, y+lineHeight*3, 127, 191, "Temps restant:", 1, 5, 100);
    PA_16cText(1, 16, y+lineHeight*4, 127, 191, "Score:", 1, 5, 100);
    PA_16cText(1, 16, y+lineHeight*5, 127, 191, "Bonus:", 1, 5, 100);
  }

void msg_about_en(void)
  {
    PA_ClearBg(0, 0);
    PA_EasyBgLoad(0, 0, msg_en_about);
    PA_ShowBg(0, 0);
  }

void msg_about_fr(void)
  {
    PA_ClearBg(0, 0);
    PA_EasyBgLoad(0, 0, msg_fr_about);
    PA_ShowBg(0, 0);
  }

void msg_highscores_en(u8 blink, score * highscores)
  {
    u8 i;
    
    PA_EasyBgLoad(1, 1, msg_en_title_highscores);
    
    PA_Init16cBg(1, 0);
    
    for (i=0; i<NB_HIGHSCORES; i++)
      {
        u8 y = 80+i*10;
        if (highscores[i].score > 0)
          {
            char txt[20];
            u8 color = blink == i ? 7 : 1;
            
            PA_16cTextAlign(ALIGN_LEFT);
            PA_16cText(1, 16, y, 135, y+20, highscores[i].name, color, 5, 100);
            
            PA_16cTextAlign(ALIGN_RIGHT);
            sprintf(txt, " %d", highscores[i].level);
            PA_16cText(1, 144, y, 159, y+20, txt, color, 5, 100);
            sprintf(txt, " %d", highscores[i].score);
            PA_16cText(1, 167, y, 239, y+20, txt, color, 5, 100);
          }
        else
          {
            PA_16cTextAlign(ALIGN_LEFT);
            PA_16cText(1, 16, y, 135, y+20, "?", 1, 5, 100);
            
            PA_16cTextAlign(ALIGN_RIGHT);
            PA_16cText(1, 144, y, 159, y+20, "?", 1, 5, 100);
            PA_16cText(1, 167, y, 239, y+20, "?", 1, 5, 100);
          }
      }
  }

void msg_highscores_fr(u8 blink, score * highscores)
  {
    u8 i;
    
    PA_EasyBgLoad(1, 1, msg_fr_title_highscores);
    
    PA_Init16cBg(1, 0);
    
    for (i=0; i<NB_HIGHSCORES; i++)
      {
        u8 y = 80+i*10;
        if (highscores[i].score > 0)
          {
            if (!(blink == i))
              {
                char txt[20];
                
                PA_16cTextAlign(ALIGN_LEFT);
                PA_16cText(1, 16, y, 135, y+20, highscores[i].name, 1, 5, 100);
                
                PA_16cTextAlign(ALIGN_RIGHT);
                sprintf(txt, " %d", highscores[i].level);
                PA_16cText(1, 144, y, 159, y+20, txt, 1, 5, 100);
                sprintf(txt, " %d", highscores[i].score);
                PA_16cText(1, 167, y, 239, y+20, txt, 1, 5, 100);
              }
          }
        else
          {
            PA_16cTextAlign(ALIGN_LEFT);
            PA_16cText(1, 16, y, 135, y+20, "?", 1, 5, 100);
            
            PA_16cTextAlign(ALIGN_RIGHT);
            PA_16cText(1, 144, y, 159, y+20, "?", 1, 5, 100);
            PA_16cText(1, 167, y, 239, y+20, "?", 1, 5, 100);
          }
      }
  }