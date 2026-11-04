
void __fastcall FUN_0054f4e0(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = DAT_00a82770;
  if (DAT_00a81fec == 0x78) {
    DAT_00a82770 = DAT_00a82770 + 1;
    if (DAT_00a82770 == 0x78) {
      DAT_00a82770 = 0;
    }
  }
  else {
    iVar1 = DAT_00a82770 + DAT_00a81fec;
    if (0x77 < iVar1) {
      iVar1 = iVar1 + -0x78;
    }
    DAT_00a81fec = DAT_00a81fec + 1;
  }
  (&DAT_00a81ff0)[iVar1 * 4] = *param_2;
  (&DAT_00a81ff4)[iVar1 * 4] = param_2[1];
  *(undefined4 *)(&DAT_00a81ff8 + iVar1 * 0x10) = param_2[2];
  *(undefined4 *)(&DAT_00a81ffc + iVar1 * 0x10) = param_2[3];
  return;
}

