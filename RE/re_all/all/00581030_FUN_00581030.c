
undefined4 FUN_00581030(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = param_1 * 0x2f0;
  piVar3 = (int *)(&DAT_00cc44e0 + iVar2);
  if (*piVar3 == 0) {
    return 0xffffffff;
  }
  FUN_00580eb0(param_1,0);
  if (*(int *)(&DAT_00cc44e4 + iVar2) != 0) {
    FUN_0056e1d0(*(int *)(&DAT_00cc44e4 + iVar2));
    *(undefined4 *)(&DAT_00cc44e4 + iVar2) = 0;
  }
  FUN_0056da50(&DAT_00cc4524 + iVar2);
  uVar1 = *(undefined4 *)(&DAT_00cc4520 + iVar2);
  FUN_0056d380(piVar3,0,0x2f0);
  *(undefined4 *)(&DAT_00cc4520 + iVar2) = uVar1;
  *piVar3 = 0;
  return 0;
}

