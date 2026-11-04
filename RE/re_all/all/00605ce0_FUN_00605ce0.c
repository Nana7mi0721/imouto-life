
undefined4 FUN_00605ce0(int *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 unaff_ESI;
  int *piVar7;
  int *piStack_40;
  undefined4 *puStack_3c;
  undefined4 uStack_38;
  undefined1 auStack_22 [22];
  int *piStack_c;
  
  piVar2 = param_2;
  piVar1 = param_1;
  if (param_1 == (int *)0x0) {
    return 0x80004003;
  }
  if (param_2 == (int *)0x0) {
    return 0x80004003;
  }
  uStack_38 = param_1;
  puStack_3c = (undefined4 *)0x605d17;
  uVar3 = (**(code **)(*param_1 + 0x2c))();
  puStack_3c = &param_1;
  piStack_40 = piVar1;
  (**(code **)(*piVar1 + 0xc))();
  (**(code **)(*piVar2 + 0xc))(piVar2,auStack_22 + -0xe);
  piVar7 = uStack_38;
  for (uVar6 = uVar3 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *piVar7 = *piStack_c;
    piStack_c = piStack_c + 1;
    piVar7 = piVar7 + 1;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(char *)piVar7 = (char)*piStack_c;
    piStack_c = (int *)((int)piStack_c + 1);
    piVar7 = (int *)((int)piVar7 + 1);
  }
  iVar4 = (**(code **)(*piVar1 + 0x14))(piVar1,auStack_22 + -10,auStack_22 + -0x12);
  if (iVar4 == 0) {
    (**(code **)(*piVar2 + 0x18))(piVar2,&uStack_38,&piStack_40);
  }
  iVar4 = (**(code **)(*piVar1 + 0x44))(piVar1,auStack_22 + -6,auStack_22 + -0xe);
  if (iVar4 == 0) {
    (**(code **)(*piVar2 + 0x48))(piVar2,auStack_22 + -0x12,&puStack_3c);
  }
  (**(code **)(*piVar1 + 0x34))(piVar1,auStack_22 + -6);
  (**(code **)(*piVar2 + 0x38))(piVar2,unaff_ESI);
  FUN_00602330(uStack_38);
  uVar5 = (**(code **)(*piVar1 + 0x2c))(piVar1);
  (**(code **)(*piVar2 + 0x30))(piVar2,uVar5);
  return 0;
}

