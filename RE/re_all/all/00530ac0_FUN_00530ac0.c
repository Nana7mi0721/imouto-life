
undefined4
FUN_00530ac0(uint param_1,undefined4 param_2,int param_3,undefined2 param_4,undefined2 param_5,
            undefined2 param_6)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  undefined2 local_8 [2];
  undefined1 local_4 [4];
  
  uVar4 = param_1;
  if (param_1 == 0xfffffffe) {
    FUN_00530d80();
    uVar4 = DAT_00a4bca8;
  }
  if ((((DAT_00cc5c60 == 0) || ((int)uVar4 < 0)) || ((uVar4 & 0x7c000000) != DAT_00cc5c88)) ||
     (((DAT_00cc5c90 <= (int)(uVar4 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc5c64 + (uVar4 & 0xffff) * 4), piVar1 == (int *)0x0)) ||
      ((*piVar1 * 0x10000 != (uVar4 & 0x3ff0000) || (piVar1[4] != 0)))))) {
    return 0xffffffff;
  }
  if (DAT_00aba250 == 0) {
    FUN_0057a980();
  }
  iVar5 = FUN_00572fc0(param_2,DAT_00aba250,local_4);
  iVar3 = param_3;
  iVar2 = piVar1[0x24366];
  iVar6 = 0;
  piVar7 = piVar1 + 0x24367;
  if (0 < iVar2) {
    do {
      if (*piVar7 == iVar5) break;
      iVar6 = iVar6 + 1;
      piVar7 = piVar7 + 8;
    } while (iVar6 < iVar2);
  }
  if (iVar6 == iVar2) {
    if (0xff < iVar2) {
      return 0xffffffff;
    }
    piVar1[0x24366] = iVar2 + 1;
  }
  *(undefined2 *)((int)piVar7 + 6) = param_4;
  *(undefined2 *)(piVar7 + 2) = param_5;
  *piVar7 = iVar5;
  *(undefined1 *)(piVar7 + 1) = 1;
  *(undefined1 *)((int)piVar7 + 5) = 1;
  *(undefined2 *)((int)piVar7 + 10) = param_6;
  FUN_00515880(param_3,&param_1,local_8);
  *(undefined2 *)(piVar7 + 3) = (undefined2)param_1;
  piVar7[4] = iVar3;
  *(undefined2 *)((int)piVar7 + 0xe) = local_8[0];
  piVar7[7] = 0;
  return 0;
}

