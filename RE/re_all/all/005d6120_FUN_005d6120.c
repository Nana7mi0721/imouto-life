
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005d6120(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined *puVar4;
  undefined4 local_190;
  undefined4 local_18c;
  int local_188;
  undefined4 local_184;
  int local_180;
  undefined4 local_17c;
  int local_178;
  undefined4 uStack_174;
  int local_170;
  undefined4 uStack_16c;
  undefined1 auStack_168 [4];
  uint uStack_164;
  undefined4 local_160;
  int iStack_15c;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  int local_148;
  undefined4 local_144;
  undefined1 local_140 [12];
  int iStack_134;
  undefined1 auStack_130 [180];
  uint uStack_7c;
  ushort uStack_74;
  
  FUN_0056d380(&local_190,0,0x38);
  local_190 = DAT_00a37e60;
  local_18c = DAT_00a37e64;
  iVar1 = FUN_0050e7d0();
  if (iVar1 == 1) {
    (**(code **)(*DAT_00f3a044 + 0x20))(DAT_00f3a044,0,local_140);
    local_188 = iStack_134;
    local_184 = 1;
    local_170 = 1;
    local_178 = (uint)(DAT_00a37d84 == 0) * 2 + 1;
    if (iStack_134 == 0x16) {
      DAT_00a37e70 = 0x20;
      uVar3 = 1;
LAB_005d61bb:
      FUN_005811a0(uVar3);
    }
    else if ((0x16 < iStack_134) && (iStack_134 < 0x1a)) {
      DAT_00a37e70 = 0x10;
      uVar3 = 0;
      goto LAB_005d61bb;
    }
    FUN_0050ea10(DAT_00aaf0d8 != 2);
  }
  else {
    FUN_00522420();
    if (DAT_00a37e94 == 0x10) {
      iVar1 = (**(code **)(*DAT_00f3a044 + 0x18))
                        (DAT_00f3a044,-(uint)(DAT_00a37eec != 0) & _DAT_00a37ef0,0x17);
      local_188 = 0x18 - (uint)(iVar1 != 0);
    }
    else {
      if (DAT_00a37e94 != 0x20) {
        FUN_0056bb10(&DAT_007fff68);
        return 0xffffffff;
      }
      local_188 = 0x16;
    }
    local_184 = 1;
    local_170 = 0;
    local_160 = DAT_00a37e98;
    local_178 = 1;
    local_158 = 0x18;
    local_14c = DAT_00a37e98;
    local_144 = 1;
    local_190 = DAT_00a37e8c;
    local_18c = DAT_00a37e90;
    local_154 = DAT_00a37e8c;
    local_150 = DAT_00a37e90;
    local_148 = local_188;
    FUN_0056bca0(&DAT_007fff18,DAT_00a37e8c,DAT_00a37e90,DAT_00a37e98);
    if (DAT_00aaf0d8 != 1) {
      FUN_0050ea10(0);
    }
    if (DAT_00aba23c != 0) {
      FUN_0056bb10(&PTR_PTR_007ffed0);
    }
  }
  local_180 = DAT_00a37d84;
  local_17c = DAT_00a37d88;
  uStack_174 = FUN_0050eb30();
  iStack_15c = (-(uint)(DAT_00a37ebc != 0) & 0x7fffffff) + 1;
  uStack_164 = (uint)(DAT_00a37d84 == 0);
  uStack_16c = 0;
  if (DAT_00a37d84 == 0) {
    local_17c = 0;
  }
  else {
    local_180 = DAT_00a37d84;
    local_17c = DAT_00a37d88;
    FUN_005d34c0(local_188,&local_180,&local_17c,0);
    DAT_00a37d84 = local_180;
  }
  DAT_00a37d88 = local_17c;
  if (DAT_00ddb370 == 1) {
    if (DAT_00f3a048 != (int *)0x0) {
LAB_005d6448:
      DAT_00ddb4b0 = 0;
      iVar1 = *DAT_00f3a048;
      uVar3 = FUN_0050e7c0(-(DAT_00aaf0e4 != 0) & 4U | -(DAT_00a210a8 != 0) & 2U | 0x20,&local_190,
                           ~-(uint)(local_170 != 0) & (uint)&local_158,&DAT_00f3a050);
      iVar1 = (**(code **)(iVar1 + 0x50))
                        (DAT_00f3a048,-(uint)(DAT_00a37eec != 0) & _DAT_00a37ef0,1,uVar3);
      if (iVar1 < 0) {
        DAT_00ddb36c = 1;
        FUN_0056bb10(&PTR_LAB_007ffe40);
        return 0xfffffffe;
      }
      puVar4 = &DAT_007ffe1c;
LAB_005d64e9:
      FUN_0056bb10(puVar4);
      DAT_00f3a04c = DAT_00f3a050;
      (**(code **)(*DAT_00f3a050 + 0x1f8))(DAT_00f3a050,1);
      goto LAB_005d6610;
    }
LAB_005d6583:
    DAT_00ddb4b0 = 0;
    iVar1 = *DAT_00f3a044;
    uVar3 = FUN_0050e7c0(-(DAT_00aaf0e4 != 0) & 4U | -(DAT_00a210a8 != 0) & 2U | 0x20,&local_190,
                         &DAT_00f3a04c);
    iVar1 = (**(code **)(iVar1 + 0x40))
                      (DAT_00f3a044,-(uint)(DAT_00a37eec != 0) & _DAT_00a37ef0,1,uVar3);
    if (iVar1 < 0) {
      FUN_0056bb10(&PTR_LAB_007ffd78);
      return 0xffffffff;
    }
    puVar4 = &DAT_007ffe1c;
  }
  else {
    (**(code **)(*DAT_00f3a044 + 0x38))
              (DAT_00f3a044,-(uint)(DAT_00a37eec != 0) & _DAT_00a37ef0,1,auStack_130);
    if (((uStack_7c & 0xffff) < 0x200) || (DAT_00ddb4b0 = 1, uStack_74 < 0x200)) {
      DAT_00ddb4b0 = 0;
    }
    _DAT_00ddb5ec = uStack_7c;
    if (DAT_00f3a048 != (int *)0x0) {
      FUN_0056bb10(&PTR_PTR_007ffe80);
      iVar1 = *DAT_00f3a048;
      uVar3 = FUN_0050e7c0((-(DAT_00ddb4b0 != 0) & 0x60U) + 0x20 | -(DAT_00aaf0e4 != 0) & 4U |
                           -(DAT_00a210a8 != 0) & 2U,auStack_168 + -0x38,
                           ~-(uint)(local_180 != 0) & (uint)auStack_168,&DAT_00f3a050);
      iVar1 = (**(code **)(iVar1 + 0x50))
                        (DAT_00f3a048,-(uint)(DAT_00a37eec != 0) & _DAT_00a37ef0,1,uVar3);
      if (iVar1 < 0) goto LAB_005d6448;
      puVar4 = &DAT_007ffdf8;
      goto LAB_005d64e9;
    }
    FUN_0056bb10(&PTR_PTR_007ffdb0);
    iVar1 = *DAT_00f3a044;
    uVar3 = FUN_0050e7c0((-(DAT_00ddb4b0 != 0) & 0x60U) + 0x20 | -(DAT_00aaf0e4 != 0) & 4U |
                         -(DAT_00a210a8 != 0) & 2U,auStack_168 + -0x38,&DAT_00f3a04c);
    iVar1 = (**(code **)(iVar1 + 0x40))
                      (DAT_00f3a044,-(uint)(DAT_00a37eec != 0) & _DAT_00a37ef0,1,uVar3);
    if (iVar1 < 0) goto LAB_005d6583;
    puVar4 = &DAT_007ffdf8;
  }
  FUN_0056bb10(puVar4);
LAB_005d6610:
  iVar1 = FUN_0050e7d0();
  if ((iVar1 == 0) && (DAT_00a37e80 != 1)) {
    uVar2 = 0;
  }
  else {
    uVar2 = (DAT_00a37ed8 << 8 | DAT_00a37edc) << 8 | DAT_00a37ee0;
  }
  (**(code **)(*DAT_00f3a04c + 0xe4))(DAT_00f3a04c,7,1);
  (**(code **)(*DAT_00f3a04c + 0xac))(DAT_00f3a04c,0,0,1,uVar2,0x3f800000,0);
  iVar1 = *DAT_00f3a04c;
  uVar3 = FUN_0050eb30(0);
  (**(code **)(iVar1 + 0x44))(DAT_00f3a04c,0,0,uVar3);
  (**(code **)(*DAT_00f3a04c + 0xac))(DAT_00f3a04c,0,0,1,uVar2,0x3f800000,0);
  iVar1 = *DAT_00f3a04c;
  uVar3 = FUN_0050eb30(0);
  (**(code **)(iVar1 + 0x44))(DAT_00f3a04c,0,0,uVar3);
  (**(code **)(*DAT_00f3a04c + 0xac))(DAT_00f3a04c,0,0,1,uVar2,0x3f800000,0);
  iVar1 = *DAT_00f3a04c;
  uVar3 = FUN_0050eb30(0);
  (**(code **)(iVar1 + 0x44))(DAT_00f3a04c,0,0,uVar3);
  (**(code **)(*DAT_00f3a04c + 0xac))(DAT_00f3a04c,0,0,1,uVar2,0x3f800000,0);
  (**(code **)(*DAT_00f3a04c + 0x38))(DAT_00f3a04c,0,&DAT_00f3a054);
  return 0;
}

