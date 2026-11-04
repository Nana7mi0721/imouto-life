
undefined4 FUN_005de640(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if (DAT_00ca39f4 == 0) {
    return 0;
  }
  if (DAT_00f3a188 == 0) {
    return 0;
  }
  if (DAT_00ca39dc != 0) {
    iVar1 = FUN_00519300(DAT_00ca39dc,0);
    if (iVar1 != 0) {
      uVar3 = *(undefined4 *)(**(int **)(iVar1 + 0x100) + 4);
      uVar4 = *(undefined4 *)(**(int **)(iVar1 + 0x100) + 8);
      if (DAT_00ca39e4 == 0) {
        uVar5 = (&DAT_00ef1f88)[DAT_00ca39e0];
        uVar2 = 1;
      }
      else {
        uVar5 = (&DAT_00ef1f98)[DAT_00ca39e0];
        uVar2 = 1;
      }
      goto LAB_005de698;
    }
    DAT_00ca39dc = 0;
  }
  uVar5 = DAT_00ef1f84;
  if (DAT_00ca39e4 == 0) {
    uVar5 = DAT_00ef1f80;
  }
  uVar2 = 0;
  uVar3 = DAT_00f3a1a0;
  uVar4 = DAT_00f3a1a4;
LAB_005de698:
  FUN_005caf30(DAT_00f3a188,DAT_00f3a18c,param_1,DAT_00f3a1a8,DAT_00f3a1b0,param_1,0,uVar2,0,uVar5,
               uVar3,uVar4,param_1,0);
  return 0;
}

