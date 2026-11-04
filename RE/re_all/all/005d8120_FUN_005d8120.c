
undefined4 FUN_005d8120(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *unaff_EBX;
  uint uVar3;
  uint uVar4;
  uint local_4;
  
  if (*unaff_EBX == 0) {
    return 0;
  }
  if (unaff_EBX[7] == 1) {
    if (param_1 == 0) {
      local_4 = 0xffffffff;
    }
    else {
      iVar1 = FUN_005d6890();
      local_4 = iVar1 - 1;
    }
    uVar3 = ((1 << ((byte)local_4 & 0x1f)) - 1U & param_1) >> ((byte)local_4 - 5 & 0x1f);
    uVar4 = uVar3 + 1;
    if (0x1f < uVar4) {
      uVar4 = uVar3 - 0x1f;
      local_4 = local_4 + 1;
    }
    do {
      uVar3 = param_1 / 100;
      if (uVar3 < 0x100001) {
        uVar3 = 0x100000;
      }
      param_1 = param_1 + uVar3;
      if (param_1 == 0) {
        uVar3 = 0xffffffff;
      }
      else {
        uVar3 = param_1 >> 1 | param_1;
        uVar3 = uVar3 | uVar3 >> 2;
        uVar3 = uVar3 | uVar3 >> 4;
        uVar3 = uVar3 | uVar3 >> 8;
        uVar3 = uVar3 >> 0x10 | uVar3;
        uVar3 = (uVar3 >> 1 & 0x55555555) + (uVar3 & 0x55555555);
        uVar3 = (uVar3 >> 2 & 0x33333333) + (uVar3 & 0x33333333);
        uVar3 = (uVar3 >> 4 & 0xf0f0f0f) + (uVar3 & 0xf0f0f0f);
        uVar3 = (uVar3 >> 8 & 0xff00ff) + (uVar3 & 0xff00ff);
        uVar3 = ((uVar3 >> 0x10) - 1) + (uVar3 & 0xffff);
      }
    } while ((uVar3 <= local_4) &&
            (((1 << ((byte)uVar3 & 0x1f)) - 1U & param_1) >> ((byte)uVar3 - 5 & 0x1f) < uVar4));
  }
  uVar3 = unaff_EBX[1];
  iVar1 = FUN_005d72e0();
  while( true ) {
    if (-1 < iVar1) {
      uVar2 = FUN_005d86c0();
      return uVar2;
    }
    uVar3 = uVar3 >> 1;
    if (uVar3 < 0x100000) break;
    iVar1 = FUN_005d72e0();
  }
  return 0;
}

