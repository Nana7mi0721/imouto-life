
void FUN_005cb6f0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined1 uVar3;
  
  if (DAT_00f3a070 != 0) {
    DAT_00ef7324 = 1;
    DAT_00ef72cc = 1;
    FUN_005badf0(DAT_00f07360);
    FUN_005c29f0(&DAT_00f130c4);
    FUN_005bc5b0(DAT_00ef7314,DAT_00ef7318);
    FUN_005c2980();
    FUN_005bb1f0(DAT_00f07678);
    FUN_005bbac0();
    FUN_005b9210(DAT_00f13214);
    FUN_005b9270(DAT_00f13218 == 1);
    FUN_005b92d0(DAT_00f1321c);
    FUN_005b9330(DAT_00f130ec);
    FUN_005b9390(DAT_00f130e0);
    if (DAT_00f130e4 == 2) {
      uVar3 = 2;
    }
    else {
      uVar3 = DAT_00f130e4 == 3;
    }
    FUN_005b9d00(uVar3);
    FUN_005b9a40(&DAT_00f0761c);
    FUN_005b9b80(DAT_00f07618);
    FUN_005b9c00(DAT_00f07670);
    FUN_005b9c80(DAT_00f07674);
    if ((DAT_00f3a070 != 0) && (DAT_00ef7324 != 0)) {
      FUN_005d2cf0(DAT_00f13674);
    }
    FUN_005bb6a0(DAT_00f13700);
    FUN_005bb6f0(DAT_00f136f4,DAT_00f136f0);
    FUN_005bb9e0(DAT_00f136f8,DAT_00f136fc);
    FUN_005bb880(DAT_00f136ec,DAT_00f136e8);
    FUN_005bb970(DAT_00f13704,DAT_00f13708);
    *(undefined4 *)(DAT_00ef1b84 + 0xc) = 1;
    piVar1 = (int *)(DAT_00ef1b84 + 0xc);
    if (*piVar1 != 0) {
      FUN_005d2dd0(*(undefined4 *)(DAT_00ef1b84 + 4),0,0,*(undefined4 *)(DAT_00ef1b84 + 8),0,0);
      *piVar1 = 0;
    }
    *(undefined4 *)(DAT_00ef1b8c + 0xc) = 1;
    puVar2 = (undefined4 *)(DAT_00ef1b8c + 0xc);
    if (*(int *)(DAT_00ef1b8c + 0xc) != 0) {
      FUN_005d2dd0(*(undefined4 *)(DAT_00ef1b8c + 4),0,0,*(undefined4 *)(DAT_00ef1b8c + 8),0,0);
      *puVar2 = 0;
    }
    *(undefined4 *)(DAT_00ef1b94 + 0xc) = 1;
    puVar2 = (undefined4 *)(DAT_00ef1b94 + 0xc);
    if (*(int *)(DAT_00ef1b94 + 0xc) != 0) {
      FUN_005d2dd0(*(undefined4 *)(DAT_00ef1b94 + 4),0,0,*(undefined4 *)(DAT_00ef1b94 + 8),0,0);
      *puVar2 = 0;
    }
    *(undefined4 *)(DAT_00ef1b9c + 0xc) = 1;
    puVar2 = (undefined4 *)(DAT_00ef1b9c + 0xc);
    if (*(int *)(DAT_00ef1b9c + 0xc) != 0) {
      FUN_005d2dd0(*(undefined4 *)(DAT_00ef1b9c + 4),0,0,*(undefined4 *)(DAT_00ef1b9c + 8),0,0);
      *puVar2 = 0;
    }
    *(undefined4 *)(DAT_00ef1ba0 + 0xc) = 1;
    puVar2 = (undefined4 *)(DAT_00ef1ba0 + 0xc);
    if (*(int *)(DAT_00ef1ba0 + 0xc) != 0) {
      FUN_005d2dd0(*(undefined4 *)(DAT_00ef1ba0 + 4),0,0,*(undefined4 *)(DAT_00ef1ba0 + 8),0,0);
      *puVar2 = 0;
    }
    *(undefined4 *)(DAT_00ef1ba4 + 0xc) = 1;
    puVar2 = (undefined4 *)(DAT_00ef1ba4 + 0xc);
    if (*(int *)(DAT_00ef1ba4 + 0xc) != 0) {
      FUN_005d2dd0(*(undefined4 *)(DAT_00ef1ba4 + 4),0,0,*(undefined4 *)(DAT_00ef1ba4 + 8),0,0);
      *puVar2 = 0;
    }
    *(undefined4 *)(DAT_00ef1ba8 + 0xc) = 1;
    puVar2 = (undefined4 *)(DAT_00ef1ba8 + 0xc);
    if (*(int *)(DAT_00ef1ba8 + 0xc) != 0) {
      FUN_005d2dd0(*(undefined4 *)(DAT_00ef1ba8 + 4),0,0,*(undefined4 *)(DAT_00ef1ba8 + 8),0,0);
      *puVar2 = 0;
    }
    FUN_005bb7f0(0,1,DAT_00ef1b84 + 4);
    FUN_005bb7f0(1,1,DAT_00ef1b8c + 4);
    FUN_005bb7f0(2,1,DAT_00ef1b94 + 4);
    FUN_005bb7f0(3,1,DAT_00ef1b9c + 4);
    FUN_005bb8e0(0,1,DAT_00ef1b84 + 4);
    FUN_005bb8e0(1,1,DAT_00ef1ba0 + 4);
    FUN_005bb8e0(2,1,DAT_00ef1ba4 + 4);
    FUN_005bb8e0(3,1,DAT_00ef1ba8 + 4);
    DAT_00ef7324 = 0;
  }
  return;
}

