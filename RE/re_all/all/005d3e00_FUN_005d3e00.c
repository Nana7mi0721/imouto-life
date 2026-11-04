
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005d3e00(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 auStack_26a [42];
  float afStack_240 [5];
  float fStack_22c;
  float fStack_228;
  float fStack_224;
  undefined4 uStack_220;
  undefined4 uStack_21c;
  undefined4 uStack_218;
  float fStack_214;
  float fStack_210;
  undefined4 auStack_208 [8];
  undefined4 local_1e8;
  undefined4 local_1e4;
  undefined4 local_1e0;
  undefined4 local_1dc;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined4 local_1d0;
  undefined4 local_1cc;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0;
  undefined4 local_1bc;
  undefined4 local_1b8;
  undefined4 uStack_1b4;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  undefined4 uStack_1a8;
  undefined4 uStack_1a4;
  int iStack_1a0;
  undefined4 uStack_19c;
  undefined4 uStack_198;
  undefined2 uStack_194;
  undefined2 uStack_192;
  undefined2 uStack_190;
  undefined2 uStack_18e;
  undefined2 uStack_18c;
  undefined2 uStack_18a;
  undefined4 uStack_188;
  undefined4 uStack_184;
  undefined4 uStack_180;
  undefined2 uStack_17c;
  undefined2 uStack_17a;
  undefined2 uStack_178;
  undefined2 uStack_176;
  undefined2 uStack_174;
  undefined2 uStack_172;
  
  FUN_00517170();
  if (DAT_00ddb5c0 == 0) {
    iVar1 = (**(code **)(*DAT_00f3a04c + 0x88))(DAT_00f3a04c,DAT_00ddb5c4,param_1,DAT_00ddb5b4);
    if (iVar1 != 0) {
      FUN_0056bca0(&PTR_LAB_007ff9b8,iVar1);
      return 0xffffffff;
    }
  }
  else {
    local_1e4 = DAT_00e80b68;
    auStack_208[7] = DAT_00e80b60;
    local_1e8 = DAT_00e80b64;
    local_1d8 = DAT_00e80b74;
    local_1e0 = DAT_00e80b6c;
    local_1dc = DAT_00e80b70;
    local_1cc = DAT_00e80644;
    local_1d4 = DAT_00e8063c;
    local_1d0 = DAT_00e80640;
    local_1c0 = DAT_00e80650;
    local_1c8 = DAT_00e80648;
    local_1c4 = DAT_00e8064c;
    local_1bc = DAT_00e80654;
    local_1b8 = DAT_00e80658;
    FUN_005a0bd0(DAT_00ddb5b4);
    iVar1 = 1;
    do {
      FUN_005a0bd0(0);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 8);
    FUN_0059d430();
    if (DAT_00a37e84 == 1) {
      (**(code **)(*DAT_00f3a04c + 0x114))(DAT_00f3a04c,0,5,1);
      uVar5 = 1;
    }
    else {
      (**(code **)(*DAT_00f3a04c + 0x114))(DAT_00f3a04c,0,5,2);
      uVar5 = 2;
    }
    uVar4 = 0;
    (**(code **)(*DAT_00f3a04c + 0x114))(DAT_00f3a04c,0,6,uVar5);
    FUN_0059a710(0);
    FUN_0059b780(0);
    FUN_0059b870(0);
    FUN_0059b8e0(0,0);
    FUN_0059b940(0);
    FUN_0056d380(&local_1d4,0,0x1b4);
    uStack_194 = 1;
    uStack_172 = 1;
    uStack_178 = 1;
    local_1d4 = 0;
    local_1d0 = 0;
    local_1cc = 2;
    local_1c8 = 0;
    local_1c4 = 0;
    local_1c0 = 0;
    local_1bc = 0xffffffff;
    local_1b8 = 0xffffffff;
    uStack_1b4 = 0xffffffff;
    uStack_1b0 = 0xffffffff;
    uStack_1ac = 0xffffffff;
    uStack_1a8 = 0xffffffff;
    uStack_1a4 = 2;
    uStack_198 = 0xffffffff;
    iStack_1a0 = DAT_00ddb5c0;
    uStack_19c = 0;
    uStack_192 = 0xffff;
    uStack_190 = 2;
    uStack_18e = 2;
    uStack_18c = 0xffff;
    uStack_18a = 2;
    uStack_180 = 0xffffffff;
    uStack_188 = 0;
    uStack_184 = 0;
    uStack_176 = 2;
    uStack_174 = 0;
    uStack_17c = 2;
    uStack_17a = 0;
    FUN_005a7d70(&local_1d4,0,0,0);
    fStack_228 = (float)DAT_00a37ea4 - (float)_DAT_00804a60;
    uStack_218 = 0xffffffff;
    afStack_240[0] = (float)DAT_00a37ea8 - (float)_DAT_00804a60;
    afStack_240[3] = -NAN;
    afStack_240[4] = (float)*param_1 / (float)DAT_00ddb5b8;
    fStack_214 = (float)param_1[2] / (float)DAT_00ddb5b8;
    fStack_22c = (float)param_1[3] / (float)DAT_00ddb5bc;
    uStack_220 = 0;
    afStack_240[1] = 0.0;
    uStack_21c = 0x3f800000;
    afStack_240[2] = 1.0;
    fStack_224 = afStack_240[0];
    fStack_210 = fStack_22c;
    FUN_005a0c60(0x144);
    puVar3 = auStack_26a + -0x12;
    (**(code **)(*DAT_00f3a04c + 0x14c))(DAT_00f3a04c,5,2,puVar3,0x1c);
    FUN_0059d460();
    iVar1 = 0;
    do {
      FUN_005a0bd0(auStack_208[iVar1],iVar1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 8);
    piVar2 = DAT_00f3a04c;
    (**(code **)(*DAT_00f3a04c + 0x114))(DAT_00f3a04c,0,5,uVar4);
    (**(code **)(*DAT_00f3a04c + 0x114))(DAT_00f3a04c,0,6,puVar3);
    FUN_0059a710(piVar2);
    DAT_00e39a54 = 1;
    FUN_005a09f0(afStack_240);
    DAT_00e39a54 = 0;
  }
  return 0;
}

