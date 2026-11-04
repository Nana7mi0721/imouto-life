
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0078c150(int param_1,int param_2,int param_3,int *param_4,int param_5,int *param_6)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  float local_37c;
  float local_378;
  float local_374;
  float local_370;
  float local_36c;
  float local_368;
  float local_364;
  float local_360;
  float local_35c;
  float local_358;
  float local_354;
  float local_350;
  float local_34c;
  float local_348;
  float local_344;
  float local_340;
  float local_33c;
  float local_338;
  float local_334;
  int local_330 [2];
  float local_328;
  float local_324;
  float local_320;
  float local_31c;
  float local_318;
  undefined **local_300 [10];
  int local_2d8;
  int *local_2d4;
  int local_2d0;
  int *local_2cc;
  int local_2c8;
  int local_2c4;
  undefined4 local_298;
  undefined4 local_294;
  undefined4 local_290;
  undefined4 local_28c;
  float local_27c;
  float local_278;
  float local_274;
  float local_270;
  float local_25c;
  undefined4 local_258;
  undefined4 local_254;
  undefined **local_250 [10];
  int local_228;
  int *local_224;
  int local_220;
  int *local_21c;
  int local_218;
  int local_214;
  undefined **local_1d8;
  undefined4 local_1d4;
  undefined4 local_1bc;
  undefined4 local_1ac;
  undefined1 local_1a4 [48];
  undefined1 local_174 [16];
  undefined1 local_164 [4];
  undefined1 local_160 [80];
  undefined1 local_110 [80];
  undefined1 local_c0 [192];
  
  FUN_0060f4b0();
  local_1d8 = &PTR_FUN_00802e34;
  local_1d4 = 8;
  local_1bc = 0;
  iVar4 = param_4[1];
  local_1ac = 0;
  if (iVar4 < 0x14) {
    FUN_0061ddb0();
    FUN_0061ddb0();
    local_25c = (float)param_6[1];
    local_258 = 0;
    local_254 = 0;
    local_300[0] = &PTR_LAB_0080453c;
    FUN_005f5190(local_160,0x10,5,FUN_0061ddb0);
    FUN_005f5190(local_110,0x10,5,FUN_0061ddb0);
    FUN_005f5190(local_c0,0x10,5,FUN_0061ddb0);
    FUN_0060f140();
    FUN_00628020(&local_1d8,param_4,local_164);
    cVar1 = FUN_00628040(param_1,param_2,param_5,param_5,local_300);
    if (((cVar1 != '\0') &&
        (fVar6 = (float10)FUN_005fcc30(&local_27c), (float10)_DAT_008298b0 < fVar6)) &&
       (local_25c < (float)param_6[1])) {
      fVar6 = (float10)FUN_005fcc30(&local_27c);
      local_378 = (float)fVar6;
      fVar6 = (float10)FUN_005fcc30(&local_27c);
      local_334 = (float)fVar6;
      fVar6 = (float10)FUN_005fcc30(&local_27c);
      local_37c = (float)fVar6;
      FUN_005fc500(&local_37c,&local_334,&local_378);
      local_278 = local_350;
      local_27c = local_354;
      local_274 = local_34c;
      local_270 = local_348;
      fVar6 = (float10)FUN_005fcc30(&local_27c);
      local_37c = (float)((float10)_DAT_00804108 / SQRT(fVar6));
      FUN_0061a860(&local_37c);
      local_330[0] = param_3;
      local_328 = local_27c;
      local_320 = local_274;
      local_324 = local_278;
      local_31c = local_270;
      local_318 = local_25c;
      local_330[1] = 0;
      (**(code **)(*param_6 + 8))(local_330,1);
    }
    FUN_00627a10();
  }
  else if ((iVar4 < 0x15) || (0x1d < iVar4)) {
    if (iVar4 == 0x1f) {
      iVar4 = 0;
      local_378 = 0.0;
      if (0 < param_4[4]) {
        do {
          iVar5 = iVar4 + param_4[6];
          FUN_005fc5f0(iVar5);
          local_220 = *(int *)(iVar5 + 0x30);
          local_21c = *(int **)(iVar5 + 0x34);
          local_218 = *(int *)(iVar5 + 0x38);
          local_214 = *(int *)(iVar5 + 0x3c);
          local_37c = *(float *)(param_4[6] + 0x40 + iVar4);
          piVar3 = (int *)FUN_005fc8d0(local_330,&local_220);
          uVar2 = FUN_005fc790(local_1a4,param_5,local_250);
          FUN_005fc5f0(uVar2);
          local_2d0 = *piVar3;
          local_2cc = (int *)piVar3[1];
          local_2c8 = piVar3[2];
          local_2c4 = piVar3[3];
          uVar2 = *(undefined4 *)(param_3 + 0xc0);
          *(float *)(param_3 + 0xc0) = local_37c;
          FUN_0078c150(param_1,param_2,param_3,local_37c,local_300,param_6);
          *(undefined4 *)(param_3 + 0xc0) = uVar2;
          local_378 = (float)((int)local_378 + 1);
          iVar4 = iVar4 + 0x50;
        } while ((int)local_378 < param_4[4]);
      }
    }
  }
  else if (iVar4 == 0x15) {
    FUN_005fc6e0(local_330);
    uVar2 = FUN_005fc5c0(&local_344,param_5 + 0x30);
    uVar2 = FUN_005fc730(&local_374,local_330,uVar2);
    FUN_005fcd10(local_330,uVar2);
    FUN_005fc8d0(&local_364,param_1 + 0x30);
    FUN_005fc8d0(&local_354,param_2 + 0x30);
    FUN_0078ebb0(&local_364,&local_354,param_6[4]);
    local_224 = param_6;
    local_220 = param_3;
    local_21c = param_4;
    FUN_0061ce50(param_5);
    local_228 = param_6[1];
    local_250[0] = &PTR_LAB_008373fc;
    FUN_0078f760(local_250,&local_364,&local_354);
    FUN_00627fe0();
  }
  else {
    FUN_005fc6e0(local_1a4);
    uVar2 = FUN_005fc5c0(local_174,(undefined4 *)(param_5 + 0x30));
    piVar3 = (int *)FUN_005fc730(local_330,local_1a4,uVar2);
    FUN_005fc5f0(local_1a4);
    local_220 = *piVar3;
    local_21c = (int *)piVar3[1];
    local_218 = piVar3[2];
    local_214 = piVar3[3];
    FUN_005fc8d0(&local_354,param_1 + 0x30);
    FUN_005fc8d0(&local_374,param_2 + 0x30);
    FUN_0078ebb0(&local_354,&local_374,param_6[4]);
    local_2d4 = param_6;
    local_2d0 = param_3;
    local_2cc = param_4;
    FUN_005fc5f0(param_5);
    local_294 = *(undefined4 *)(param_5 + 0x34);
    local_298 = *(undefined4 *)(param_5 + 0x30);
    local_290 = *(undefined4 *)(param_5 + 0x38);
    local_2d8 = param_6[1];
    local_28c = *(undefined4 *)(param_5 + 0x3c);
    local_300[0] = &PTR_LAB_008373f0;
    local_364 = local_354;
    local_360 = local_350;
    local_35c = local_34c;
    local_358 = local_348;
    if (local_374 < local_354) {
      local_364 = local_374;
    }
    if (local_370 < local_350) {
      local_360 = local_370;
    }
    if (local_36c < local_34c) {
      local_35c = local_36c;
    }
    if (local_368 < local_348) {
      local_358 = local_368;
    }
    local_344 = local_354;
    local_340 = local_350;
    local_33c = local_34c;
    local_338 = local_348;
    if (local_354 < local_374) {
      local_344 = local_374;
    }
    if (local_350 < local_370) {
      local_340 = local_370;
    }
    if (local_34c < local_36c) {
      local_33c = local_36c;
    }
    if (local_348 < local_368) {
      local_338 = local_368;
    }
    (**(code **)(*param_4 + 0x2c))(local_300,&local_364,&local_344);
    FUN_00627fe0();
  }
  local_1d8 = &PTR_FUN_00802e78;
  FUN_00611c80();
  return;
}

