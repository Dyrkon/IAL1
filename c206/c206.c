
/* ******************************* c206.c *********************************** */
/*  Předmět: Algoritmy (IAL) - FIT VUT v Brně                                 */
/*  Úkol: c206 - Dvousměrně vázaný lineární seznam                            */
/*  Návrh a referenční implementace: Bohuslav Křena, říjen 2001               */
/*  Vytvořil: Martin Tuček, říjen 2004                                        */
/*  Upravil: Kamil Jeřábek, září 2020                                         */
/*           Daniel Dolejška, září 2021                                       */
/* ************************************************************************** */
/*
** Implementujte abstraktní datový typ dvousměrně vázaný lineární seznam.
** Užitečným obsahem prvku seznamu je hodnota typu int. Seznam bude jako datová
** abstrakce reprezentován proměnnou typu DLList (DL znamená Doubly-Linked
** a slouží pro odlišení jmen konstant, typů a funkcí od jmen u jednosměrně
** vázaného lineárního seznamu). Definici konstant a typů naleznete
** v hlavičkovém souboru c206.h.
**
** Vaším úkolem je implementovat následující operace, které spolu s výše
** uvedenou datovou částí abstrakce tvoří abstraktní datový typ obousměrně
** vázaný lineární seznam:
**
**      DLL_Init ........... inicializace seznamu před prvním použitím,
**      DLL_Dispose ........ zrušení všech prvků seznamu,
**      DLL_InsertFirst .... vložení prvku na začátek seznamu,
**      DLL_InsertLast ..... vložení prvku na konec seznamu,
**      DLL_First .......... nastavení aktivity na první prvek,
**      DLL_Last ........... nastavení aktivity na poslední prvek,
**      DLL_GetFirst ....... vrací hodnotu prvního prvku,
**      DLL_GetLast ........ vrací hodnotu posledního prvku,
**      DLL_DeleteFirst .... zruší první prvek seznamu,
**      DLL_DeleteLast ..... zruší poslední prvek seznamu,
**      DLL_DeleteAfter .... ruší prvek za aktivním prvkem,
**      DLL_DeleteBefore ... ruší prvek před aktivním prvkem,
**      DLL_InsertAfter .... vloží nový prvek za aktivní prvek seznamu,
**      DLL_InsertBefore ... vloží nový prvek před aktivní prvek seznamu,
**      DLL_GetValue ....... vrací hodnotu aktivního prvku,
**      DLL_SetValue ....... přepíše obsah aktivního prvku novou hodnotou,
**      DLL_Previous ....... posune aktivitu na předchozí prvek seznamu,
**      DLL_Next ........... posune aktivitu na další prvek seznamu,
**      DLL_IsActive ....... zjišťuje aktivitu seznamu.
**
** Při implementaci jednotlivých funkcí nevolejte žádnou z funkcí
** implementovaných v rámci tohoto příkladu, není-li u funkce explicitně
 * uvedeno něco jiného.
**
** Nemusíte ošetřovat situaci, kdy místo legálního ukazatele na seznam
** předá někdo jako parametr hodnotu NULL.
**
** Svou implementaci vhodně komentujte!
**
** Terminologická poznámka: Jazyk C nepoužívá pojem procedura.
** Proto zde používáme pojem funkce i pro operace, které by byly
** v algoritmickém jazyce Pascalovského typu implemenovány jako procedury
** (v jazyce C procedurám odpovídají funkce vracející typ void).
**
**/

#include "c206.h"

int error_flag;
int solved;

/**
 * Vytiskne upozornění na to, že došlo k chybě.
 * Tato funkce bude volána z některých dále implementovaných operací.
 */
void DLL_Error() {
    printf("*ERROR* The program has performed an illegal operation.\n");
    error_flag = TRUE;
}

/**
 * Provede inicializaci seznamu list před jeho prvním použitím (tzn. žádná
 * z následujících funkcí nebude volána nad neinicializovaným seznamem).
 * Tato inicializace se nikdy nebude provádět nad již inicializovaným seznamem,
 * a proto tuto možnost neošetřujte.
 * Vždy předpokládejte, že neinicializované proměnné mají nedefinovanou hodnotu.
 *
 * @param list Ukazatel na strukturu dvousměrně vázaného seznamu
 */
void DLL_Init( DLList *list ) {
<<<<<<< HEAD
    list->activeElement = NULL; // Nastavíme ukazatele na prvky na NULL
=======
    list->activeElement = NULL;
>>>>>>> origin/advanced
    list->firstElement = NULL;
    list->lastElement = NULL;

}

/**
 * Zruší všechny prvky seznamu list a uvede seznam do stavu, v jakém se nacházel
 * po inicializaci.
 * Rušené prvky seznamu budou korektně uvolněny voláním operace free.
 *
 * @param list Ukazatel na inicializovanou strukturu dvousměrně vázaného seznamu
 */
void DLL_Dispose( DLList *list ) {
<<<<<<< HEAD
    list->activeElement = NULL;                 // Nastavíme aktivní prvek na NULL a uděláme si pomocné proměnné na mazání
    DLLElementPtr removed = list->firstElement;
    DLLElementPtr nextRemoved;

    while (removed->nextElement != NULL)    // Dokud existuje prvek na vymazání, opakujeme
=======
    if (list->firstElement == NULL)
        return;

    list->activeElement = NULL;
    DLLElementPtr removed = list->firstElement;
    DLLElementPtr nextRemoved;

    while (removed != NULL)
>>>>>>> origin/advanced
    {
        nextRemoved = removed->nextElement;
        free(removed);
        removed = nextRemoved;
    }

    list->firstElement = NULL; // Nastavíme první a poslední element na NULL
    list->lastElement = NULL;
}

/**
 * Vloží nový prvek na začátek seznamu list.
 * V případě, že není dostatek paměti pro nový prvek při operaci malloc,
 * volá funkci DLL_Error().
 *
 * @param list Ukazatel na inicializovanou strukturu dvousměrně vázaného seznamu
 * @param data Hodnota k vložení na začátek seznamu
 */
void DLL_InsertFirst( DLList *list, int data ) {
    if (!list)
        return;

    DLLElementPtr newElement;

    if ((newElement = (DLLElementPtr)malloc(sizeof(struct DLLElement))) == NULL)
    {
        DLL_Error();
        return;
    }

    newElement->data = data;
    newElement->previousElement = NULL;
    newElement->nextElement = list->firstElement;

    if (list->firstElement)
        list->firstElement->previousElement = newElement;
    else
        list->lastElement = newElement;

    list->firstElement = newElement;
}

/**
 * Vloží nový prvek na konec seznamu list (symetrická operace k DLL_InsertFirst).
 * V případě, že není dostatek paměti pro nový prvek při operaci malloc,
 * volá funkci DLL_Error().
 *
 * @param list Ukazatel na inicializovanou strukturu dvousměrně vázaného seznamu
 * @param data Hodnota k vložení na konec seznamu
 */
void DLL_InsertLast( DLList *list, int data ) {
    if (!list)
        return;

    DLLElementPtr newElement;

    if ((newElement = (DLLElementPtr)malloc(sizeof(struct DLLElement))) == NULL)
    {
        DLL_Error();
        return;
    }

    newElement->data = data;
    newElement->previousElement = list->lastElement;
    newElement->nextElement = NULL;

    if (list->lastElement)
        list->lastElement->nextElement = newElement;
    else
        list->firstElement = newElement;

    list->lastElement = newElement;
}

/**
 * Nastaví první prvek seznamu list jako aktivní.
 * Funkci implementujte jako jediný příkaz (nepočítáme-li return),
 * aniž byste testovali, zda je seznam list prázdný.
 *
 * @param list Ukazatel na inicializovanou strukturu dvousměrně vázaného seznamu
 */
void DLL_First( DLList *list ) {
    list->activeElement = list->firstElement; // Nastavíme jako aktivní prvek ten první
}

/**
 * Nastaví poslední prvek seznamu list jako aktivní.
 * Funkci implementujte jako jediný příkaz (nepočítáme-li return),
 * aniž byste testovali, zda je seznam list prázdný.
 *
 * @param list Ukazatel na inicializovanou strukturu dvousměrně vázaného seznamu
 */
void DLL_Last( DLList *list ) {
    list != NULL ? list->activeElement = list->lastElement : NULL; // Pokud ukazatel na list není NULL, nastavíme jako aktivní prvek ten poslední
}

/**
 * Prostřednictvím parametru dataPtr vrátí hodnotu prvního prvku seznamu list.
 * Pokud je seznam list prázdný, volá funkci DLL_Error().
 *
 * @param list Ukazatel na inicializovanou strukturu dvousměrně vázaného seznamu
 * @param dataPtr Ukazatel na cílovou proměnnou
 */
void DLL_GetFirst( DLList *list, int *dataPtr ) {
    if (list->firstElement == NULL) // Pokud první element je NULL voláme error
    {
        DLL_Error();
        return;
    }

    *dataPtr = list->firstElement->data; // Předáme si data pomocí dereference do proměnné parametru
}

/**
 * Prostřednictvím parametru dataPtr vrátí hodnotu posledního prvku seznamu list.
 * Pokud je seznam list prázdný, volá funkci DLL_Error().
 *
 * @param list Ukazatel na inicializovanou strukturu dvousměrně vázaného seznamu
 * @param dataPtr Ukazatel na cílovou proměnnou
 */
void DLL_GetLast( DLList *list, int *dataPtr ) {
    if (list->lastElement == NULL) // Pokud poslední element je NULL voláme error
    {
        DLL_Error();
        return;
    }

    *dataPtr = list->lastElement->data; // Předáme si data pomocí dereference do proměnné parametru
}

/**
 * Zruší první prvek seznamu list.
 * Pokud byl první prvek aktivní, aktivita se ztrácí.
 * Pokud byl seznam list prázdný, nic se neděje.
 *
 * @param list Ukazatel na inicializovanou strukturu dvousměrně vázaného seznamu
 */
void DLL_DeleteFirst( DLList *list ) {
    if (list->firstElement == NULL && list->lastElement == NULL)
        return;

    if (list->firstElement == list->activeElement)
        list->activeElement = NULL;
    if (list->lastElement == list->firstElement)
        list->lastElement = NULL;

    DLLElementPtr toBeRemoved = list->firstElement;

    list->firstElement = list->firstElement->nextElement;
    free(toBeRemoved);
}

/**
 * Zruší poslední prvek seznamu list.
 * Pokud byl poslední prvek aktivní, aktivita seznamu se ztrácí.
 * Pokud byl seznam list prázdný, nic se neděje.
 *
 * @param list Ukazatel na inicializovanou strukturu dvousměrně vázaného seznamu
 */
void DLL_DeleteLast( DLList *list ) {
    if (list->firstElement == NULL && list->lastElement == NULL)
        return;

    if (list->lastElement == list->activeElement)
        list->activeElement = NULL;
    if (list->lastElement == list->firstElement)
        list->firstElement = NULL;
    else
        list->lastElement->previousElement->nextElement = NULL;

    DLLElementPtr toBeRemoved = list->lastElement;

    list->lastElement = toBeRemoved->previousElement;
    free(toBeRemoved);
}

/**
 * Zruší prvek seznamu list za aktivním prvkem.
 * Pokud je seznam list neaktivní nebo pokud je aktivní prvek
 * posledním prvkem seznamu, nic se neděje.
 *
 * @param list Ukazatel na inicializovanou strukturu dvousměrně vázaného seznamu
 */
void DLL_DeleteAfter( DLList *list ) {
    if (list->activeElement == NULL || list->lastElement == list->activeElement)
        return;

    DLLElementPtr toRemove = list->activeElement->nextElement;

    list->activeElement->nextElement = toRemove->nextElement;

    if (toRemove == list->lastElement)
        list->lastElement = list->activeElement;
    else
        toRemove->nextElement->previousElement = list->activeElement;

    free(toRemove);
}

/**
 * Zruší prvek před aktivním prvkem seznamu list .
 * Pokud je seznam list neaktivní nebo pokud je aktivní prvek
 * prvním prvkem seznamu, nic se neděje.
 *
 * @param list Ukazatel na inicializovanou strukturu dvousměrně vázaného seznamu
 */
void DLL_DeleteBefore( DLList *list ) {
    if (list->activeElement == list->firstElement || list->activeElement == NULL)
        return;

    DLLElementPtr toRemove = list->activeElement->previousElement;

    list->activeElement->previousElement = toRemove->previousElement;

    if (list->firstElement)
        list->firstElement = list->activeElement;
    else
        toRemove->previousElement->nextElement = list->activeElement;
    free(toRemove);
}

/**
 * Vloží prvek za aktivní prvek seznamu list.
 * Pokud nebyl seznam list aktivní, nic se neděje.
 * V případě, že není dostatek paměti pro nový prvek při operaci malloc,
 * volá funkci DLL_Error().
 *
 * @param list Ukazatel na inicializovanou strukturu dvousměrně vázaného seznamu
 * @param data Hodnota k vložení do seznamu za právě aktivní prvek
 */
void DLL_InsertAfter( DLList *list, int data ) {
    if (list->activeElement == NULL) // Ověříme, že aktivní element není NULL

    DLLElementPtr newElement;

    if ((newElement = (DLLElementPtr) malloc(sizeof(struct DLLElement))) == NULL) // Naalokuju si struckt, pokud se to nepovede, volám ERROR
    {
        DLL_Error();
        return;
    }

    newElement->data = data; // Nahraju si data

    newElement->previousElement = list->activeElement; // Přiřadím si předchozí a nasledující element
    newElement->nextElement = list->activeElement->nextElement;

    if (list->activeElement == list->lastElement) // Pokud poslední a aktivní element jsou stejné, tak se nám posledním prvkem stane náš nový
        list->lastElement = newElement;
    else
        list->activeElement->nextElement->previousElement = newElement; // Ukazatel na předchozí prvek dalšího prvku bude nový element

    list->activeElement->nextElement = newElement;
}

/**
 * Vloží prvek před aktivní prvek seznamu list.
 * Pokud nebyl seznam list aktivní, nic se neděje.
 * V případě, že není dostatek paměti pro nový prvek při operaci malloc,
 * volá funkci DLL_Error().
 *
 * @param list Ukazatel na inicializovanou strukturu dvousměrně vázaného seznamu
 * @param data Hodnota k vložení do seznamu před právě aktivní prvek
 */
void DLL_InsertBefore( DLList *list, int data ) {
    if (list->activeElement == NULL) // Ověříme, že aktivní element není NULL
        return;

    DLLElementPtr newElement;

    if ((newElement = (DLLElementPtr) malloc(sizeof(struct DLLElement))) == NULL) // Naalokuju si struckt, pokud se to nepovede, volám ERROR
    {
        DLL_Error();
        return;
    }

    newElement->data = data; // Nahraju si data

    newElement->previousElement = list->activeElement->previousElement;  // Přiřadím si předchozí a nasledující element
    newElement->nextElement = list->activeElement;

    if (list->activeElement == list->firstElement) // Pokud první a aktivní element jsou stejné, tak se nám prvním prvkem stane náš nový
        list->firstElement = newElement;
    else
        list->activeElement->previousElement->nextElement = newElement; // Ukazatel na další prvek předchozího prvku bude nový element

    list->activeElement->previousElement = newElement; // Ukazatel na předchozí prvek aktivního prvku bude ukazovat na nový prvek
}

/**
 * Prostřednictvím parametru dataPtr vrátí hodnotu aktivního prvku seznamu list.
 * Pokud seznam list není aktivní, volá funkci DLL_Error ().
 *
 * @param list Ukazatel na inicializovanou strukturu dvousměrně vázaného seznamu
 * @param dataPtr Ukazatel na cílovou proměnnou
 */
void DLL_GetValue( DLList *list, int *dataPtr ) {
    if (list->activeElement == NULL) // Ověříme, že aktivní element není NULL
    {
        DLL_Error();
        return;
    }

    *dataPtr = list->activeElement->data; // Z aktivního prvku si dereferencí prvek předám do ukazatele z parametru
}

/**
 * Přepíše obsah aktivního prvku seznamu list.
 * Pokud seznam list není aktivní, nedělá nic.
 *
 * @param list Ukazatel na inicializovanou strukturu dvousměrně vázaného seznamu
 * @param data Nová hodnota právě aktivního prvku
 */
void DLL_SetValue( DLList *list, int data ) {
    if (list->activeElement == NULL) // Ověříme, že aktivní element není NULL
        return;

    list->activeElement->data = data; // Do aktivního elementu předám data
}

/**
 * Posune aktivitu na následující prvek seznamu list.
 * Není-li seznam aktivní, nedělá nic.
 * Všimněte si, že při aktivitě na posledním prvku se seznam stane neaktivním.
 *
 * @param list Ukazatel na inicializovanou strukturu dvousměrně vázaného seznamu
 */
void DLL_Next( DLList *list ) {
<<<<<<< HEAD
    if (list->activeElement == NULL) // Ověříme, že aktivní element není NULL
        return;

    list->activeElement = list->activeElement->nextElement; // Do aktivního prvku předám prvek za ním
}


/**
 * Posune aktivitu na předchozí prvek seznamu list.
 * Není-li seznam aktivní, nedělá nic.
 * Všimněte si, že při aktivitě na prvním prvku se seznam stane neaktivním.
 *
 * @param list Ukazatel na inicializovanou strukturu dvousměrně vázaného seznamu
 */
void DLL_Previous( DLList *list ) {
	if (list->activeElement == NULL) // Ověříme, že aktivní element není NULL
        return;

    list->activeElement = list->activeElement->previousElement; // Do aktivního prvku předám prvek před ním
}

/**
 * Je-li seznam list aktivní, vrací nenulovou hodnotu, jinak vrací 0.
 * Funkci je vhodné implementovat jedním příkazem return.
 *
 * @param list Ukazatel na inicializovanou strukturu dvousměrně vázaného seznamu
 *
 * @returns Nenulovou hodnotu v případě aktivity prvku seznamu, jinak nulu
 */
int DLL_IsActive( DLList *list ) {
    return list->activeElement == NULL ? 0 : 1; // V případě, že je aktivní element 0, vrací 0, jinak 1
}

/* Konec c206.c */