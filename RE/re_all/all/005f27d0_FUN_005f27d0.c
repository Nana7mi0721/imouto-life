
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005f27d0(undefined4 param_1,float param_2,float param_3)

{
  undefined4 *puVar1;
  undefined1 local_80 [128];
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if (DAT_00dda4d0 < 0) {
    DAT_00dda4d0 = FUN_005f2360(0);
    if (DAT_00dda4d0 < 0) {
      FUN_005764b0(PTR_s_Mono_pso_00a057b0,0xffffffff,0x7ffd,local_80,0x80,0x4b0);
      FUN_0056bca0(&DAT_00802650,local_80);
      return 0xffffffff;
    }
    FUN_00580830(DAT_00dda4d0,&DAT_00dda4d0);
  }
  puVar1 = *(undefined4 **)(DAT_00ef1ba8 + 8);
  *puVar1 = _DAT_0080264c;
  puVar1[1] = _DAT_00802648;
  puVar1[2] = _DAT_00802644;
  puVar1[3] = 0;
  puVar1[4] = (float)_DAT_007d9bc0 * param_3;
  puVar1[5] = (float)_DAT_007d9bb0 * param_2 - param_3 * (float)_DAT_007d9ba8;
  puVar1[6] = param_2 * (float)_DAT_007d9ba0;
  puVar1[7] = 0;
  *(undefined4 *)(DAT_00ef1ba8 + 0xc) = 1;
  FUN_005bc8e0(DAT_00ef1ba8);
  FUN_005f23c0(DAT_00dda4d0,0,1,0xffffffff,0);
  return 0;
}

