
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint * FUN_005bc700(uint param_1,undefined4 param_2)

{
  uint *puVar1;
  int iVar2;
  undefined *puVar3;
  uint local_18 [6];
  
  FUN_0056da60(&DAT_00cc7cf4,"..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxGraphicsD3D11.cpp",
               0x263f);
  if ((param_1 & 0xf) == 0) {
    puVar1 = (uint *)FUN_0056e030(param_1 + 0x18,
                                  "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxGraphicsD3D11.cpp"
                                  ,0x264a);
    if (puVar1 == (uint *)0x0) {
      puVar3 = &DAT_007fd6b4;
    }
    else {
      FUN_0056d380(puVar1,0,param_1 + 0x18);
      FUN_0056d380(local_18,0,0x18);
      local_18[0] = param_1;
      local_18[1] = 0;
      local_18[2] = 4;
      local_18[3] = 0;
      iVar2 = FUN_005d4e80(local_18,0,puVar1 + 1,param_2);
      if (iVar2 == 0) {
        *puVar1 = param_1;
        puVar1[2] = (uint)(puVar1 + 6);
        puVar1[3] = 0;
        if (DAT_00ef1b80 != (uint *)0x0) {
          puVar1[4] = (uint)DAT_00ef1b80;
          *(uint **)((int)DAT_00ef1b80 + 0x14) = puVar1;
        }
        _DAT_00ef1b7c = _DAT_00ef1b7c + 1;
        DAT_00ef1b80 = puVar1;
        FUN_0056dac0(&DAT_00cc7cf4);
        return puVar1;
      }
      puVar3 = &DAT_007fd670;
    }
    FUN_0056bca0(puVar3);
    if (puVar1 != (uint *)0x0) {
      if (puVar1[1] != 0) {
        FUN_005d1ec0(puVar1[1]);
        puVar1[1] = 0;
      }
      FUN_0056e1d0(puVar1);
    }
  }
  else {
    FUN_0056bca0(&DAT_007fd6f0);
  }
  FUN_0056dac0(&DAT_00cc7cf4);
  return (uint *)0x0;
}

