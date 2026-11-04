
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005221c0(undefined8 param_1,undefined8 param_2)

{
  undefined1 local_80 [128];
  
  _DAT_00a3d350 = param_1;
  _DAT_00a3d358 = param_2;
  FUN_00586020(local_80,param_1,param_2,(double)(_DAT_00a381bc * (float)DAT_00a381b4),
               (double)(_DAT_00a381bc * (float)DAT_00a381b8));
  FUN_00521d40(local_80);
  return 0;
}

