
uint FUN_005673c0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  uVar3 = 0;
  piVar1 = &DAT_00aa84b8;
  while (*piVar1 != 0) {
    piVar1 = piVar1 + 0x17;
    uVar3 = uVar3 + 1;
    if (piVar1 == &DAT_00aae0b8) {
      return 0xffffffff;
    }
  }
  if (uVar3 == 0x100) {
    return 0xffffffff;
  }
  iVar4 = uVar3 * 0x5c;
  FUN_0056d380(&DAT_00aa84b8 + uVar3 * 0x17,0,0x5c);
  *(int *)(&DAT_00aa84e8 + iVar4) = param_1 * 2 + 2;
  iVar2 = FUN_0056e050(param_1 * 4 + 4,"..\\..\\..\\..\\Source\\Library\\Main\\DxInputString.cpp",
                       0xe0b);
  *(int *)(&DAT_00aa84e0 + iVar4) = iVar2;
  *(int *)(&DAT_00aa84e4 + iVar4) = iVar2 + 2 + param_1 * 2;
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  *(undefined4 *)(&DAT_00aa84ec + iVar4) = param_2;
  *(undefined4 *)(&DAT_00aa84f0 + iVar4) = param_3;
  *(undefined4 *)(&DAT_00aa84f8 + iVar4) = param_5;
  *(int *)(&DAT_00aa84cc + iVar4) = param_1;
  *(undefined4 *)(&DAT_00aa84f4 + iVar4) = param_4;
  *(undefined4 *)(&DAT_00aa84fc + iVar4) = param_6;
  (&DAT_00aa84b8)[uVar3 * 0x17] = 1;
  iVar2 = DAT_00aae0b8;
  *(undefined4 *)(&DAT_00aa84d0 + iVar4) = 0xffffffff;
  *(undefined4 *)(&DAT_00aa84d4 + iVar4) = 0xffffffff;
  (&DAT_00aa84bc)[uVar3 * 0x17] = iVar2;
  DAT_00aae0b8 = DAT_00aae0b8 + 1;
  if (0x3fe < DAT_00aae0b8) {
    DAT_00aae0b8 = 0;
  }
  DAT_00aa7008 = 1;
  if (DAT_00aa700c != 1) {
    if (DAT_00aba1bc != (code *)0x0) {
      (*DAT_00aba1bc)(DAT_00a20bec,1);
    }
    DAT_00aa700c = 1;
  }
  FUN_00567320();
  return ((&DAT_00aa84bc)[uVar3 * 0x17] | 0x2400) << 0x10 | uVar3;
}

