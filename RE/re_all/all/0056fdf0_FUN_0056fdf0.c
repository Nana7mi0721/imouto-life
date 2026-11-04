
undefined4 FUN_0056fdf0(int param_1,int param_2,uint param_3,int param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int unaff_EDI;
  uint uVar6;
  int local_8;
  
  iVar1 = param_1;
  iVar5 = 0;
  iVar4 = -1;
  iVar2 = FUN_00572fc0(param_1,*(undefined4 *)(unaff_EDI + 0x38),&param_1);
  uVar6 = param_3;
  while (param_3 = uVar6, iVar2 != 0) {
    if ((((iVar2 == 0x5c) || (iVar2 == 0x2f)) || (iVar2 == 0)) || (iVar2 == 0x3a)) {
      iVar4 = iVar5;
      local_8 = param_1;
    }
    iVar5 = iVar5 + param_1;
    iVar2 = FUN_00572fc0(iVar5 + iVar1,*(undefined4 *)(unaff_EDI + 0x38),&param_1);
    uVar6 = param_3;
  }
  if (param_2 != 0) {
    if (iVar4 == -1) {
      uVar3 = thunk_FUN_00572ac0(*(undefined4 *)(unaff_EDI + 0x38));
      uVar3 = param_3 / uVar3;
      uVar6 = param_3;
      iVar5 = iVar1;
    }
    else {
      if (uVar6 <= (uint)(local_8 + iVar4)) goto LAB_0056feb7;
      uVar3 = thunk_FUN_00572ac0(*(undefined4 *)(unaff_EDI + 0x38));
      uVar3 = ((uVar6 - local_8) - iVar4) / uVar3;
      iVar5 = local_8 + iVar4 + iVar1;
    }
    FUN_00577120(*(undefined4 *)(unaff_EDI + 0x38),param_2,uVar6,iVar5,uVar3);
  }
LAB_0056feb7:
  iVar5 = param_4;
  if (param_4 != 0) {
    if (iVar4 == -1) {
      thunk_FUN_00573310(0,*(undefined4 *)(unaff_EDI + 0x38),param_4,param_5);
    }
    else if (iVar4 + 1U < param_5) {
      FUN_0056d420(param_4,iVar1,iVar4);
      thunk_FUN_00573310(0,*(undefined4 *)(unaff_EDI + 0x38),iVar4 + iVar5,0x7fffffff);
      return 0;
    }
  }
  return 0;
}

