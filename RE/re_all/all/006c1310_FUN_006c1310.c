
int FUN_006c1310(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  undefined1 auStack_800 [8];
  uint uStack_7f8;
  int iStack_7f4;
  uint uStack_7f0;
  
  (**(code **)(param_1 + 4))(*(undefined4 *)(param_1 + 0x10),0,0,2);
  uVar6 = (**(code **)(param_1 + 8))(*(undefined4 *)(param_1 + 0x10));
  *(undefined8 *)(param_1 + 0x38) = uVar6;
  uVar1 = *(uint *)(param_1 + 0x38);
  iVar5 = *(int *)(param_1 + 0x3c);
  *(uint *)(param_1 + 0x30) = uVar1;
  *(int *)(param_1 + 0x34) = iVar5;
  if ((iVar5 < 1) && (iVar5 < 0)) {
    return -0x80;
  }
  iVar2 = *(int *)(param_1 + 0x1c);
  iVar3 = *(int *)(iVar2 + 0xc);
  uVar4 = *(uint *)(iVar2 + 8);
  if ((iVar5 <= iVar3) && ((iVar5 < iVar3 || (uVar1 < uVar4)))) {
    return -0x89;
  }
  iVar5 = FUN_006c1420(param_1,auStack_800,uVar1,iVar5,*(undefined4 *)(iVar2 + 0x28),
                       *(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x20));
  if (-1 < iVar5) {
    iVar5 = ((int)uStack_7f0 >> 0x1f) + iStack_7f4 + (uint)CARRY4(uStack_7f0,uStack_7f8);
    *(uint *)(param_1 + 0x38) = uStack_7f0 + uStack_7f8;
    *(int *)(param_1 + 0x3c) = iVar5;
    if ((iVar5 <= iVar3) && ((iVar5 < iVar3 || (*(uint *)(param_1 + 0x38) < uVar4)))) {
      return -0x89;
    }
    iVar5 = FUN_006c1710(param_1,uVar4,iVar3,auStack_800,0x40,(undefined4 *)(param_1 + 0x28),
                         param_1 + 0x20,param_1 + 0x24);
  }
  return iVar5;
}

