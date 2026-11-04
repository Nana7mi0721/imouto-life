
undefined4
FUN_005808a0(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  bool bVar5;
  
  iVar3 = param_1 * 0x2f0;
  piVar4 = (int *)(&DAT_00cc44e0 + iVar3);
  if (*piVar4 == 0) {
    uVar1 = *(undefined4 *)(&DAT_00cc4520 + iVar3);
    FUN_0056d380(piVar4,0,0x2f0);
    *(undefined4 *)(&DAT_00cc450c + iVar3) = param_2;
    *(undefined4 *)(&DAT_00cc474c + iVar3) = param_6;
    iVar2 = DAT_00aba250;
    bVar5 = DAT_00aba250 == 0;
    *(int *)(&DAT_00cc4508 + iVar3) = param_1 << 0x1a;
    *(undefined4 *)(&DAT_00cc4520 + iVar3) = uVar1;
    *(int *)(&DAT_00cc4510 + iVar3) = param_3;
    *(undefined4 *)(&DAT_00cc4744 + iVar3) = param_4;
    *(undefined4 *)(&DAT_00cc4748 + iVar3) = param_5;
    if (bVar5) {
      FUN_0057a980();
      iVar2 = DAT_00aba250;
    }
    FUN_005764b0(*(undefined4 *)(&DAT_00cc474c + iVar3),0xffffffff,iVar2,iVar3 + 0xcc4750,0x80,0x4b0
                );
    iVar2 = FUN_0056e050(param_3 * 4,"..\\..\\..\\..\\Source\\Library\\Main\\DxHandle.cpp",0x56);
    *(int *)(&DAT_00cc44e4 + iVar3) = iVar2;
    if (iVar2 != 0) {
      *(undefined4 *)(&DAT_00cc44e8 + iVar3) = 0xffffffff;
      *(undefined4 *)(&DAT_00cc44ec + iVar3) = 0;
      *(undefined4 *)(&DAT_00cc44f0 + iVar3) = 0;
      *(undefined **)(&DAT_00cc44f4 + iVar3) = &DAT_00cc44f8 + iVar3;
      *(undefined **)(&DAT_00cc4500 + iVar3) = &DAT_00cc44e8 + iVar3;
      *(undefined4 *)(&DAT_00cc44f8 + iVar3) = 0xffffffff;
      *(undefined4 *)(&DAT_00cc44fc + iVar3) = 0;
      *(undefined4 *)(&DAT_00cc4504 + iVar3) = 0;
      FUN_0056da30(&DAT_00cc4524 + iVar3);
      *piVar4 = 1;
      return 0;
    }
  }
  return 0xffffffff;
}

