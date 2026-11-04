
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00529ed0(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar5;
  undefined8 uVar4;
  undefined8 uVar6;
  undefined4 local_74;
  float local_70;
  undefined1 local_6c [4];
  undefined1 local_68 [4];
  float local_64;
  float local_60;
  float local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  float local_4c;
  float local_48;
  float local_44;
  undefined1 local_40 [64];
  
  uVar4 = CONCAT44(&local_74,&local_70);
  local_70 = 0.0;
  local_74 = 0;
  uVar5 = DAT_00a38120;
  FUN_00515880();
  FUN_00515880(param_1,local_68,local_6c,uVar5,uVar4);
  uVar3 = DAT_00a38190;
  uVar2 = DAT_00a3818c;
  uVar1 = DAT_00a38188;
  uVar5 = DAT_00a38184;
  if (DAT_00a38590 == 0) {
    uVar6 = CONCAT44(local_74,local_70);
    uVar4 = 0;
  }
  else {
    if (DAT_00a38108 != 0) {
      FUN_005217e0(0,0,local_70,local_74);
      DAT_00a38184 = uVar5;
      DAT_00a38188 = uVar1;
      DAT_00a3818c = uVar2;
      DAT_00a38190 = uVar3;
      goto LAB_00529f9c;
    }
    uVar6 = CONCAT44(DAT_00a38190,DAT_00a3818c);
    uVar4 = CONCAT44(DAT_00a38188,DAT_00a38184);
  }
  FUN_005217e0(uVar4,uVar6);
LAB_00529f9c:
  if (DAT_00a38590 == 0) {
    _DAT_00a384f8 = 0x3ff0000000000000;
    FUN_00524b70();
    FUN_00585060();
    FUN_00521b80(local_40);
    _DAT_00a3d350 = (double)DAT_00a381b4 * _DAT_00804a60;
    _DAT_00a3d358 = (double)DAT_00a381b8 * _DAT_00804a60;
    FUN_005221c0(_DAT_00a3d350,_DAT_00a3d358);
    local_70 = (float)(DAT_00a381b8 / 2) / (float)_DAT_007d5908;
    local_64 = (float)DAT_00a381b4 * (float)_DAT_00804a60;
    local_60 = (float)_DAT_00804a60 * (float)DAT_00a381b8;
    local_5c = -local_70;
    local_44 = local_5c + (float)_DAT_00802e18;
    local_58 = 0;
    local_54 = 0x3f800000;
    local_50 = 0;
    local_4c = local_64;
    local_48 = local_60;
    FUN_005277c0(local_64,local_60,local_5c,local_64,local_60,local_44,0,0x3f800000,0);
    _DAT_00a38500 = _DAT_007d5900;
    DAT_00a384e0 = 0;
    FUN_00524b70();
    _DAT_00a384e8 = (double)((float)_DAT_00829898 * local_70 + (float)_DAT_007d0a60);
    local_70 = local_70 + (float)_DAT_007d58f8;
    _DAT_00a384f0 = (double)local_70;
    FUN_00524b70();
  }
  return 0;
}

