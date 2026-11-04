
int FUN_00651320(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  iVar1 = param_1;
  iVar2 = 1;
  uVar6 = *(uint *)(param_1 + 0x48);
  uVar7 = *(uint *)(param_1 + 0x44);
  if (*(uint *)(param_1 + 0x40) == 1) {
    param_4 = 0;
  }
  if (uVar7 == 0xffffffff) {
    uVar7 = *(uint *)(param_1 + 0x38);
  }
  if (uVar6 == 0xffffffff) {
    uVar6 = *(uint *)(param_1 + 0x3c);
  }
  uVar4 = *(uint *)(param_1 + 0x4c);
  if (*(uint *)(param_1 + 0x4c) == 0xffffffff) {
    uVar4 = *(uint *)(param_1 + 0x40);
  }
  uVar5 = 0;
  if (((uVar7 != 0) && (uVar6 != 0)) && (uVar4 != 0)) {
    if (*(uint *)(param_1 + 0x38) < -uVar7) {
      param_1 = ((*(uint *)(param_1 + 0x38) - 1) + uVar7) / uVar7;
    }
    else {
      param_1 = 0;
    }
    if (*(uint *)(iVar1 + 0x3c) < -uVar6) {
      uVar5 = ((*(uint *)(iVar1 + 0x3c) - 1) + uVar6) / uVar6;
    }
    if (*(uint *)(iVar1 + 0x40) < -uVar4) {
      uVar3 = ((*(uint *)(iVar1 + 0x40) - 1) + uVar4) / uVar4;
    }
    else {
      uVar3 = 0;
    }
    if (*(short *)(iVar1 + 0x7e) == 2) {
      param_4 = (param_5 & 0xffff) * uVar3 + param_4 / uVar4;
    }
    else {
      param_4 = param_4 / uVar4;
    }
    iVar2 = (param_4 * uVar5 + param_3 / uVar6) * param_1 + param_2 / uVar7;
  }
  return iVar2;
}

