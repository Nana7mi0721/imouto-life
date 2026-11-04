
undefined4 FUN_005a7e00(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *local_4c [19];
  
  if (param_1 != 0) {
    local_4c[0] = &LAB_0059d420;
    uVar2 = FUN_0057ffd0(local_4c);
    return uVar2;
  }
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  if ((DAT_00e79678 != 0) && (iVar3 = FUN_0052ea40(), iVar3 == 0)) {
    if (DAT_00e79688 == 0) {
      FUN_0059d430();
    }
    if (DAT_00e7968c == 0) {
      iVar3 = 0;
      switch(DAT_00e79680) {
      case 1:
        iVar3 = DAT_00e79678;
        break;
      case 2:
        iVar3 = DAT_00e79678 / 2;
        break;
      case 3:
        iVar3 = DAT_00e79678 + -1;
        break;
      case 4:
        iVar3 = DAT_00e79678 / 3;
        break;
      case 5:
      case 6:
        iVar3 = DAT_00e79678 + -2;
      }
      FUN_005a7ce0();
      iVar1 = DAT_00e7967c + DAT_00e79674 * 3;
      FUN_005d3b40(DAT_00e79680,iVar3,*(undefined4 *)(&DAT_00e39a5c + iVar1 * 4),
                   *(undefined4 *)(&DAT_007da3e8 + iVar1 * 4));
      DAT_00a37de4 = DAT_00a37de4 + 1;
    }
  }
  DAT_00e79678 = 0;
  DAT_00e39a58 = *(undefined4 *)(&DAT_00e39a5c + (DAT_00e7967c + DAT_00e79674 * 3) * 4);
  return 0;
}

