
undefined4 FUN_00652520(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  iVar2 = FUN_0065f680(param_1);
  if ((iVar2 == 0) || (*(int *)(param_1 + 0xb0) == 0)) {
    return 0;
  }
  if ((*(byte *)(param_1 + 0xc) & 0x20) == 0) {
    iVar2 = (**(code **)(param_1 + 0x1fc))(param_1);
    if (iVar2 == 0) {
      return 0;
    }
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x20;
  }
  *(uint *)(param_1 + 0x1ec) = param_2;
  uVar3 = *(uint *)(param_1 + 0x44);
  if (*(uint *)(param_1 + 0x38) < -uVar3) {
    uVar3 = ((*(uint *)(param_1 + 0x38) - 1) + uVar3) / uVar3;
  }
  else {
    uVar3 = 0;
  }
  *(uint *)(param_1 + 0x1bc) = (param_2 % uVar3) * *(int *)(param_1 + 0x48);
  uVar3 = *(uint *)(param_1 + 0x48);
  if (*(uint *)(param_1 + 0x3c) < -uVar3) {
    uVar3 = ((*(uint *)(param_1 + 0x3c) - 1) + uVar3) / uVar3;
  }
  else {
    uVar3 = 0;
  }
  uVar1 = *(uint *)(param_1 + 0xc);
  *(uint *)(param_1 + 0x1e8) = (param_2 % uVar3) * *(int *)(param_1 + 0x44);
  *(uint *)(param_1 + 0xc) = uVar1 & 0xffefffff;
  if ((uVar1 & 0x20000) == 0) {
    *(undefined4 *)(param_1 + 0x25c) = *(undefined4 *)(param_1 + 0x24c);
    *(undefined4 *)(param_1 + 0x260) = *(undefined4 *)(*(int *)(param_1 + 0xb0) + param_2 * 8);
  }
  else {
    *(undefined4 *)(param_1 + 0x25c) = 0;
    *(undefined4 *)(param_1 + 0x260) = 0;
  }
  uVar4 = (**(code **)(param_1 + 0x200))(param_1,param_2 / *(uint *)(param_1 + 0xa4));
  return uVar4;
}

