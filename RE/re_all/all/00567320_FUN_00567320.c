
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00567320(void)

{
  char cVar1;
  int iVar2;
  
  iVar2 = FUN_005501a0();
  while ((iVar2 == 0 && (cVar1 = FUN_005648a0(1), cVar1 != '\0'))) {
    iVar2 = FUN_005501a0();
  }
  _DAT_00aa4fc8 = 0;
  DAT_00aa4fdc = 0;
  DAT_00aa57e4 = 0;
  DAT_00aa57e8 = 0;
  if ((((DAT_00a20bec != 0) && (DAT_00aa700c == 1)) && (DAT_00aa7010 == 1)) &&
     (iVar2 = (*DAT_00aba12c)(DAT_00a20bec), iVar2 != 0)) {
    FUN_0056d380(&DAT_00aa5ff8,0,0x400);
    (*DAT_00aba13c)(iVar2,0x15,4,0);
    (*DAT_00aba130)(DAT_00a20bec,iVar2);
  }
  return 0;
}

