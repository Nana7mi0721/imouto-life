
undefined4 FUN_006b95f0(int param_1,undefined4 param_2,uint *param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  
  switch(param_2) {
  case 1:
    if ((param_1 != 0) && (param_3 != (uint *)0x0)) {
      if (param_4 == 4) {
        *param_3 = 7;
        return 0;
      }
      return 0xfffffff6;
    }
    break;
  default:
    return 0xffffffe9;
  case 3:
    if ((param_1 != 0) && (param_3 != (uint *)0x0)) {
      if (param_4 != 4) {
        return 0xfffffff6;
      }
      uVar1 = *param_3;
      if ((int)uVar1 < 0) {
        return 0xfffffff6;
      }
      if ((int)uVar1 < 8) {
        *(uint *)(param_1 + 0xd114) = uVar1;
        return 0;
      }
      return 0xfffffff6;
    }
    break;
  case 5:
    if ((param_1 != 0) && (param_3 != (uint *)0x0)) {
      if (param_4 != 8) {
        return 0xfffffff6;
      }
      uVar1 = param_3[1];
      uVar3 = *param_3;
      if (((int)uVar1 < 1) && ((int)uVar1 < 0)) {
        return 0xfffffff6;
      }
      *(uint *)(param_1 + 0x360) = uVar3;
      *(uint *)(param_1 + 0x364) = uVar1;
      uVar5 = __allshr();
      *(uint *)(param_1 + 0x350) = (uint)uVar5 - (uint)*(byte *)(param_1 + 0x369);
      iVar4 = (int)((ulonglong)uVar5 >> 0x20) -
              (uint)((uint)uVar5 < (uint)*(byte *)(param_1 + 0x369));
      *(int *)(param_1 + 0x354) = iVar4;
      uVar2 = (1 << ((byte)*(undefined4 *)(param_1 + 0x3c) & 0x1f)) - 1;
      uVar3 = uVar2 & uVar3;
      *(uint *)(param_1 + 0x358) = uVar3 + *(uint *)(param_1 + 0x350);
      *(uint *)(param_1 + 0x35c) =
           ((int)uVar2 >> 0x1f & uVar1) + iVar4 + (uint)CARRY4(uVar3,*(uint *)(param_1 + 0x350));
      return 0;
    }
    break;
  case 7:
    if ((param_1 != 0) && (param_3 != (uint *)0x0)) {
      if (param_4 == 8) {
        *(uint *)(param_1 + 0xd358) = *param_3;
        *(uint *)(param_1 + 0xd35c) = param_3[1];
        return 0;
      }
      return 0xfffffff6;
    }
  }
  return 0xffffffff;
}

