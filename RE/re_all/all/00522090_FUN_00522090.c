
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_00522090(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
            undefined1 param_13)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 local_b0 [24];
  undefined1 local_98 [24];
  undefined4 local_80 [32];
  
  _DAT_00a3d268 = param_1;
  _DAT_00a3d26c = param_2;
  _DAT_00a3d270 = param_3;
  _DAT_00a3d274 = param_4;
  _DAT_00a3d278 = param_5;
  _DAT_00a3d27c = param_6;
  _DAT_00a3d280 = param_7;
  _DAT_00a3d284 = param_8;
  _DAT_00a3d288 = param_9;
  _DAT_00a3d28c = param_10;
  _DAT_00a3d290 = param_11;
  _DAT_00a3d294 = param_12;
  _DAT_00a3d348 = 1;
  FUN_005860c0(local_b0,&param_7,&param_1);
  FUN_005860f0(local_98,local_b0,&param_13);
  FUN_005860f0(&DAT_00a3d298,local_98,local_b0);
  FUN_00586070(&DAT_00a3d298,&DAT_00a3d298);
  FUN_00586430(local_80,&DAT_00a3d268,&DAT_00a3d280,&DAT_00a3d298);
  FUN_00521cd0(local_80);
  puVar2 = local_80;
  puVar3 = &DAT_00a3d2c8;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_0051bfc0();
  return 0;
}

