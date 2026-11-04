
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0078cb90(int *param_1,int param_2,int param_3,int param_4,int *param_5,int param_6,
                 int *param_7,undefined ***param_8)

{
  int iVar1;
  undefined4 uVar2;
  float fVar3;
  char cVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined ***pppuVar7;
  float10 fVar8;
  undefined ***pppuStack_3ac;
  float local_398;
  undefined **local_394;
  float local_390;
  float local_38c;
  float local_388;
  undefined **local_384;
  float local_380;
  float fStack_37c;
  float fStack_378;
  undefined **ppuStack_374;
  float local_370 [4];
  float local_360;
  undefined **local_35c;
  float local_358;
  float local_354;
  float local_350;
  float local_34c;
  float local_348;
  undefined4 local_344;
  float local_340;
  float local_33c;
  undefined **local_338;
  float local_334 [4];
  undefined **local_324 [4];
  undefined **local_314 [4];
  undefined **local_304 [3];
  undefined4 uStack_2f8;
  undefined **local_2f4;
  undefined **local_2f0;
  undefined **local_2ec;
  undefined **local_2e8;
  undefined **local_2e4;
  undefined4 uStack_2e0;
  undefined4 uStack_2dc;
  undefined4 uStack_2d8;
  undefined4 uStack_2d4;
  float fStack_2d0;
  float fStack_2c0;
  float fStack_2bc;
  float fStack_2b8;
  undefined **ppuStack_2b4;
  undefined1 auStack_2b0 [4];
  float fStack_2ac;
  float fStack_2a8;
  undefined1 auStack_2a4 [16];
  int local_294 [5];
  undefined1 local_280 [48];
  float local_250;
  float local_24c;
  float local_248;
  undefined **local_244;
  undefined **local_240 [28];
  undefined **ppuStack_1d0;
  undefined **ppuStack_1cc;
  undefined **ppuStack_1c8;
  undefined **ppuStack_1c4;
  undefined4 uStack_1c0;
  undefined4 uStack_1bc;
  undefined4 uStack_1b8;
  undefined4 uStack_1b4;
  float fStack_1b0;
  int local_19c;
  undefined4 local_198;
  undefined ***local_194;
  int iStack_178;
  int *piStack_170;
  int iStack_16c;
  int *piStack_168;
  undefined1 local_164 [4];
  undefined1 local_160 [80];
  undefined1 local_110 [80];
  undefined1 local_c0 [188];
  undefined4 uStack_4;
  
  iVar1 = param_5[1];
  if (iVar1 < 0x14) {
    pppuStack_3ac = (undefined ***)0x78cbb9;
    FUN_0061ddb0();
    pppuStack_3ac = (undefined ***)0x78cbc5;
    FUN_0061ddb0();
    pppuStack_3ac = (undefined ***)FUN_0061ddb0;
    local_19c = param_7[1];
    local_198 = 0;
    local_240[0] = &PTR_LAB_0080453c;
    local_194 = param_8;
    FUN_005f5190(local_160,0x10,5);
    pppuStack_3ac = (undefined ***)FUN_0061ddb0;
    FUN_005f5190(local_110,0x10,5);
    pppuStack_3ac = (undefined ***)FUN_0061ddb0;
    FUN_005f5190(local_c0,0x10,5);
    pppuStack_3ac = (undefined ***)0x78cc46;
    FUN_0060f140();
    pppuStack_3ac = &local_394;
    local_394 = &PTR_LAB_008040c4;
    FUN_0078ff90(param_1,param_5,local_164);
    pppuStack_3ac = local_240;
    cVar4 = (**(code **)(local_294[0] + 4))(param_2,param_3,param_6,param_6);
    if (((cVar4 != '\0') &&
        (fVar8 = (float10)FUN_005fcc30(&ppuStack_1d0), (float10)_DAT_008298b0 < fVar8)) &&
       (fStack_1b0 < (float)param_7[1])) {
      fVar8 = (float10)FUN_005fcc30(&ppuStack_1d0);
      pppuStack_3ac = (undefined ***)(float)((float10)_DAT_00804108 / SQRT(fVar8));
      FUN_0061a860(&pppuStack_3ac);
      local_2f0 = ppuStack_1d0;
      uStack_2f8 = uStack_4;
      local_2e4 = ppuStack_1c4;
      local_2ec = ppuStack_1cc;
      local_2e8 = ppuStack_1c8;
      uStack_2d8 = uStack_1b8;
      uStack_2e0 = uStack_1c0;
      uStack_2dc = uStack_1bc;
      fStack_2d0 = fStack_1b0;
      local_2f4 = (undefined **)0x0;
      uStack_2d4 = uStack_1b4;
      (**(code **)(*param_7 + 8))(&uStack_2f8,1);
    }
    FUN_00627a10();
    return;
  }
  if ((iVar1 < 0x15) || (0x1d < iVar1)) {
    if ((iVar1 == 0x1f) && (local_394 = (undefined **)0x0, 0 < param_5[4])) {
      local_398 = 0.0;
      do {
        fVar3 = local_398;
        pppuVar7 = (undefined ***)(param_5[6] + (int)local_398);
        pppuStack_3ac = pppuVar7;
        FUN_005fc5f0();
        local_2f4 = pppuVar7[0xc];
        local_2f0 = pppuVar7[0xd];
        local_2ec = pppuVar7[0xe];
        pppuStack_3ac = &local_2f4;
        local_2e8 = pppuVar7[0xf];
        uVar5 = *(undefined4 *)(param_5[6] + 0x40 + (int)fVar3);
        puVar6 = (undefined4 *)FUN_005fc8d0(local_294);
        pppuStack_3ac = local_324;
        pppuStack_3ac = (undefined ***)FUN_005fc790(&local_2e4,param_6);
        FUN_005fc5f0();
        local_250 = (float)*puVar6;
        local_24c = (float)puVar6[1];
        local_248 = (float)puVar6[2];
        local_244 = (undefined **)puVar6[3];
        uVar2 = *(undefined4 *)(param_4 + 0xc0);
        pppuStack_3ac = param_8;
        *(undefined4 *)(param_4 + 0xc0) = uVar5;
        FUN_0078cb90(param_1,param_2,param_3,param_4,uVar5,local_280,param_7);
        *(undefined4 *)(param_4 + 0xc0) = uVar2;
        local_394 = (undefined **)((int)local_394 + 1);
        local_398 = (float)((int)local_398 + 0x50);
      } while ((int)local_394 < param_5[4]);
    }
    return;
  }
  if (iVar1 == 0x15) {
    pppuStack_3ac = &local_2e4;
    FUN_005fc6e0();
    pppuStack_3ac = (undefined ***)(param_6 + 0x30);
    uVar5 = FUN_005fc5c0(&local_390);
    pppuStack_3ac = (undefined ***)FUN_005fc730(&local_380,&local_2e4,uVar5);
    FUN_005fcd10(&local_2e4);
    pppuStack_3ac = (undefined ***)(param_2 + 0x30);
    FUN_005fc8d0(&local_344);
    pppuStack_3ac = (undefined ***)(param_3 + 0x30);
    FUN_005fc8d0(local_334);
    pppuStack_3ac = local_304;
    local_390 = 0.0;
    local_38c = 0.0;
    local_388 = 0.0;
    local_384 = (undefined **)0x0;
    fVar8 = (float10)FUN_005fccf0();
    local_394 = (undefined **)(float)fVar8;
    pppuStack_3ac = local_304;
    fVar8 = (float10)FUN_005fccd0();
    local_398 = (float)fVar8;
    pppuStack_3ac = local_304;
    fVar8 = (float10)FUN_005fccb0();
    local_350 = (float)fVar8;
    pppuStack_3ac = local_314;
    fVar8 = (float10)FUN_005fccf0();
    local_348 = (float)fVar8;
    pppuStack_3ac = local_314;
    fVar8 = (float10)FUN_005fccd0();
    local_354 = (float)fVar8;
    pppuStack_3ac = local_314;
    fVar8 = (float10)FUN_005fccb0();
    local_358 = (float)fVar8;
    pppuStack_3ac = local_324;
    fVar8 = (float10)FUN_005fccf0();
    local_34c = (float)fVar8;
    pppuStack_3ac = local_324;
    fVar8 = (float10)FUN_005fccd0();
    local_360 = (float)fVar8;
    pppuStack_3ac = local_324;
    fVar8 = (float10)FUN_005fccb0();
    pppuStack_3ac = &local_394;
    local_35c = (undefined **)(float)fVar8;
    FUN_005fcc50(&local_35c,&local_360,&local_34c,&local_358,&local_354,&local_348,&local_350,
                 &local_398);
    pppuStack_3ac = &local_2e4;
    FUN_005fc5f0();
    local_250 = local_390;
    local_24c = local_38c;
    local_244 = local_384;
    local_248 = local_388;
    pppuStack_3ac = (undefined ***)0x78cfbc;
    fVar8 = (float10)(**(code **)(*param_5 + 0x28))();
    pppuStack_3ac = (undefined ***)(float)fVar8;
    FUN_0078f0f0(param_1,param_2,param_3,param_6);
    iStack_16c = param_4;
    pppuStack_3ac = &ppuStack_2b4;
    iStack_178 = param_7[1];
    piStack_170 = param_7;
    piStack_168 = param_5;
    local_240[0] = &PTR_LAB_00837414;
    (**(code **)(*param_1 + 4))(local_280,auStack_2a4);
    FUN_0078f940(&local_24c,&local_350,&local_340,auStack_2b0,&fStack_2c0);
    FUN_00627fe0();
    return;
  }
  pppuStack_3ac = &local_2e4;
  FUN_005fc6e0();
  pppuStack_3ac = (undefined ***)(param_6 + 0x30);
  uVar5 = FUN_005fc5c0(&local_344);
  pppuStack_3ac = (undefined ***)FUN_005fc730(local_294,&local_2e4,uVar5);
  FUN_005fcd10(&local_2e4);
  pppuStack_3ac = (undefined ***)(param_2 + 0x30);
  FUN_005fc8d0(local_334);
  pppuStack_3ac = (undefined ***)(param_3 + 0x30);
  FUN_005fc8d0(local_370);
  pppuStack_3ac = local_304;
  local_344 = 0;
  local_340 = 0.0;
  local_33c = 0.0;
  local_338 = (undefined **)0x0;
  fVar8 = (float10)FUN_005fccf0();
  local_35c = (undefined **)(float)fVar8;
  pppuStack_3ac = local_304;
  fVar8 = (float10)FUN_005fccd0();
  local_360 = (float)fVar8;
  pppuStack_3ac = local_304;
  fVar8 = (float10)FUN_005fccb0();
  local_34c = (float)fVar8;
  pppuStack_3ac = local_314;
  fVar8 = (float10)FUN_005fccf0();
  local_358 = (float)fVar8;
  pppuStack_3ac = local_314;
  fVar8 = (float10)FUN_005fccd0();
  local_354 = (float)fVar8;
  pppuStack_3ac = local_314;
  fVar8 = (float10)FUN_005fccb0();
  local_348 = (float)fVar8;
  pppuStack_3ac = local_324;
  fVar8 = (float10)FUN_005fccf0();
  local_350 = (float)fVar8;
  pppuStack_3ac = local_324;
  fVar8 = (float10)FUN_005fccd0();
  local_394 = (undefined **)(float)fVar8;
  pppuStack_3ac = local_324;
  fVar8 = (float10)FUN_005fccb0();
  pppuStack_3ac = &local_35c;
  local_398 = (float)fVar8;
  FUN_005fcc50(&local_398,&local_394,&local_350,&local_348,&local_354,&local_358,&local_34c,
               &local_360);
  pppuStack_3ac = &local_2e4;
  FUN_005fc5f0();
  local_250 = (float)local_344;
  local_248 = local_33c;
  local_24c = local_340;
  local_244 = local_338;
  pppuStack_3ac = (undefined ***)0x78d243;
  fVar8 = (float10)(**(code **)(*param_5 + 0x28))();
  pppuStack_3ac = (undefined ***)(float)fVar8;
  FUN_0078f0f0(param_1,param_2,param_3,param_6);
  iStack_16c = param_4;
  pppuStack_3ac = &ppuStack_2b4;
  iStack_178 = param_7[1];
  piStack_170 = param_7;
  piStack_168 = param_5;
  local_240[0] = &PTR_LAB_00837408;
  (**(code **)(*param_1 + 4))(local_280,auStack_2a4);
  local_398 = local_33c;
  local_394 = local_338;
  local_390 = local_334[0];
  if (fStack_378 < local_33c) {
    local_398 = fStack_378;
  }
  if ((float)ppuStack_374 < (float)local_338) {
    local_394 = ppuStack_374;
  }
  if (local_370[0] < local_334[0]) {
    local_390 = local_370[0];
  }
  local_388 = local_33c;
  local_384 = local_338;
  local_380 = local_334[0];
  if (fStack_37c <= local_340) {
    fStack_37c = local_340;
  }
  if (local_33c < fStack_378) {
    local_388 = fStack_378;
  }
  if ((float)local_338 < (float)ppuStack_374) {
    local_384 = ppuStack_374;
  }
  if (local_334[0] < local_370[0]) {
    local_380 = local_370[0];
  }
  local_398 = local_398 + fStack_2ac;
  local_394 = (undefined **)((float)local_394 + fStack_2a8);
  local_38c = fStack_2c0 + fStack_37c;
  local_388 = local_388 + fStack_2bc;
  local_384 = (undefined **)((float)local_384 + fStack_2b8);
  (**(code **)(*param_5 + 0x2c))(&local_24c,local_370 + -0xb,&local_38c);
  FUN_00627fe0();
  return;
}

