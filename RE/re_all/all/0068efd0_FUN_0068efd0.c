
void FUN_0068efd0(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined1 uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int iStack_20;
  int *piStack_1c;
  int iStack_18;
  int iStack_14;
  
  piVar3 = param_1;
  iVar1 = param_1[0x70];
  piStack_1c = (int *)(iVar1 + 0x20);
  iVar5 = FUN_0068f130(param_1,piStack_1c);
  if (param_1[0x19] == 3) {
    iVar2 = *param_1;
    *(int *)(iVar2 + 0x18) = iVar5;
    *(int *)(iVar2 + 0x1c) = *piStack_1c;
    *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(iVar1 + 0x24);
    *(undefined4 *)(iVar2 + 0x24) = *(undefined4 *)(iVar1 + 0x28);
    *(undefined4 *)(*param_1 + 0x14) = 0x60;
  }
  else {
    *(undefined4 *)(*param_1 + 0x14) = 0x61;
    *(int *)(*param_1 + 0x18) = iVar5;
  }
  (**(code **)(*param_1 + 4))(param_1,1);
  piVar6 = (int *)(**(code **)(param_1[1] + 8))(param_1,1,iVar5,param_1[0x19]);
  iStack_20 = 0;
  if (param_1[0x19] < 1) {
    *(int **)(iVar1 + 0x10) = piVar6;
    *(int *)(iVar1 + 0x14) = iVar5;
    return;
  }
  piVar11 = piVar6;
  iStack_14 = iVar5;
  do {
    iVar2 = *piStack_1c;
    iVar7 = iStack_14 / iVar2;
    iStack_18 = 0;
    if (0 < iVar2) {
      param_1 = (int *)0x0;
      do {
        uVar4 = FUN_0068f220(piVar3,iStack_20,iStack_18,iVar2 + -1);
        for (iVar9 = (int)param_1; iVar9 < iVar5; iVar9 = iVar9 + iStack_14) {
          iVar8 = 0;
          if (0 < iVar7) {
            do {
              iVar10 = *piVar11 + iVar8;
              iVar8 = iVar8 + 1;
              *(undefined1 *)(iVar9 + iVar10) = uVar4;
            } while (iVar8 < iVar7);
          }
        }
        param_1 = (int *)((int)param_1 + iVar7);
        iStack_18 = iStack_18 + 1;
      } while (iStack_18 < iVar2);
    }
    piStack_1c = piStack_1c + 1;
    iStack_20 = iStack_20 + 1;
    piVar11 = piVar11 + 1;
    iStack_14 = iVar7;
  } while (iStack_20 < piVar3[0x19]);
  *(int *)(iVar1 + 0x14) = iVar5;
  *(int **)(iVar1 + 0x10) = piVar6;
  return;
}

