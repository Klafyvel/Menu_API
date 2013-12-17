/*    Copyright (C) 2013 LEVY-FALK Hugo

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/
#include <stdlib.h>
#include <stdio.h>

#include "menu.h"

void riri(void);
void fifi(void);
void loulou(void);
void donald(void);
void picsou(void);


int main(void)
{
    Menu myMenu;
    Menu mySubMenu;
    char titre[] = "Titre du menu";
    Menu_new(&myMenu, titre);
    Menu_new(&mySubMenu, "Sous Menu");

    Item item_riri;
    Menu_newItem(&item_riri, riri, "Riri");
    Item item_fifi;
    Menu_newItem(&item_fifi, fifi, "Fifi");
    Item item_loulou;
    Menu_newItem(&item_loulou, loulou, "Loulou");
    Item item_donald;
    Menu_newItem(&item_donald, donald, "Donald");
    Item item_picsou;
    Menu_newItem(&item_picsou, picsou, "Picsou");

    Item item_sousMenu;
    Menu_newItemSubMenu(&item_sousMenu, &mySubMenu, "Sous Menu");

    Menu_addItem(&myMenu, &item_riri);
    Menu_addItem(&myMenu, &item_fifi);
    Menu_addItem(&myMenu, &item_loulou);
    Menu_addItem(&myMenu, &item_donald);
    Menu_addItem(&myMenu, &item_picsou);
    Menu_addItem(&myMenu, &item_sousMenu);

    Menu_addItem(&mySubMenu, &item_donald);

    Menu_removeItemById(&myMenu, 1);
    Menu_removeItemByLabel(&myMenu, "Donald");

    Menu_addItem(&myMenu, &item_donald);

    while(1)
    {
        int action = Menu_choose(&myMenu);

        if(action == -1)
        {
            break;
        }
        else
        {
            if(!Menu_do(&myMenu, action))
            {
                printf("Erreur lors du lancement d'une action.\n");
            }
        }
    }

    return 0;
}


void riri(void) 
{
    printf("RIRI !\n");
	getchar();
}
void fifi(void) 
{
    printf("FIFI !\n");
	getchar();
}
void loulou(void) 
{
    printf("LOULOU !\n");
	getchar();
}
void donald(void) 
{
    printf("DONALD !\n");
	getchar();
}
void picsou(void) 
{
    printf("PICSOU !\n");
	getchar();
}
