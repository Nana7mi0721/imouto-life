
undefined4 FUN_0079a620(undefined4 *param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  sbyte sVar4;
  int iVar5;
  undefined4 *puVar6;
  
  puVar6 = param_1;
  for (iVar2 = 0x4b; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  sVar4 = 0;
  if (param_4 == 0) {
    if (((param_2 != 8000) && (param_2 != 12000)) && (param_2 != 16000)) {
      return 0xffffffff;
    }
    if (((param_3 != 8000) && (param_3 != 12000)) &&
       ((param_3 != 16000 && ((param_3 != 24000 && (param_3 != 48000)))))) {
      return 0xffffffff;
    }
    param_1[0x49] =
         (int)(char)(&DAT_008376e2)
                    [((int)((param_3 >> 0xc) - (uint)(16000 < param_3)) >> (24000 < param_3)) +
                     ((int)((param_2 >> 0xc) - (uint)(16000 < param_2)) >> (24000 < param_2)) * 5];
  }
  else {
    if (((((param_2 != 8000) && (param_2 != 12000)) && (param_2 != 16000)) &&
        ((param_2 != 24000 && (param_2 != 48000)))) ||
       ((param_3 != 8000 && ((param_3 != 12000 && (param_3 != 16000)))))) {
      return 0xffffffff;
    }
    param_1[0x49] =
         (int)(char)(&DAT_008376d4)
                    [((int)((param_3 >> 0xc) - (uint)(16000 < param_3)) >> (24000 < param_3)) +
                     ((int)((param_2 >> 0xc) - (uint)(16000 < param_2)) >> (24000 < param_2)) * 3];
  }
  param_1[0x47] = param_2 / 1000;
  param_1[0x48] = param_3 / 1000;
  param_1[0x43] = (param_2 / 1000) * 10;
  if (param_2 < param_3) {
    if (param_3 == param_2 * 2) {
      param_1[0x42] = 1;
    }
    else {
      param_1[0x42] = 2;
      sVar4 = 1;
    }
  }
  else if (param_3 < param_2) {
    param_1[0x42] = 3;
    if (param_3 * 4 == param_2 * 3) {
      param_1[0x46] = 3;
      param_1[0x45] = 0x12;
      param_1[0x4a] = &DAT_00837890;
    }
    else if (param_3 * 3 == param_2 * 2) {
      param_1[0x46] = 2;
      param_1[0x45] = 0x12;
      param_1[0x4a] = &DAT_008378cc;
    }
    else if (param_3 * 2 == param_2) {
      param_1[0x46] = 1;
      param_1[0x45] = 0x18;
      param_1[0x4a] = &DAT_008378f4;
    }
    else if (param_3 * 3 == param_2) {
      param_1[0x46] = 1;
      param_1[0x45] = 0x24;
      param_1[0x4a] = &DAT_00837910;
    }
    else if (param_3 * 4 == param_2) {
      param_1[0x46] = 1;
      param_1[0x45] = 0x24;
      param_1[0x4a] = &DAT_00837938;
    }
    else {
      if (param_3 * 6 != param_2) {
        return 0xffffffff;
      }
      param_1[0x46] = 1;
      param_1[0x45] = 0x24;
      param_1[0x4a] = &DAT_00837960;
    }
  }
  else {
    param_1[0x42] = 0;
  }
  iVar5 = (int)(short)param_3;
  uVar1 = ((param_2 << sVar4 + 0xe) / param_3) * 4;
  iVar3 = (param_3 >> 0xf) + 1 >> 1;
  param_1[0x44] = uVar1;
  iVar2 = ((int)((uVar1 & 0xffff) * iVar5) >> 0x10) + ((int)uVar1 >> 0x10) * iVar5 + iVar3 * uVar1;
  while (iVar2 < param_2 << sVar4) {
    uVar1 = param_1[0x44] + 1;
    param_1[0x44] = uVar1;
    iVar2 = ((int)((uVar1 & 0xffff) * iVar5) >> 0x10) + ((int)uVar1 >> 0x10) * iVar5 + uVar1 * iVar3
    ;
  }
  return 0;
}

