
int FUN_00651ec0(int param_1,uint param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x1f0);
  iVar1 = FUN_00652630(param_1,1);
  if (iVar1 != 0) {
    if (param_2 < *(uint *)(param_1 + 0xa8)) {
      if ((param_4 == -1) || (iVar2 < param_4)) {
        param_4 = iVar2;
      }
      iVar2 = FUN_00652100(param_1,param_2);
      if (iVar2 != 0) {
        iVar2 = (**(code **)(param_1 + 0x224))
                          (param_1,param_3,param_4,param_2 / *(uint *)(param_1 + 0xa4));
        if (iVar2 != 0) {
          (**(code **)(param_1 + 0x28c))(param_1,param_3,param_4);
          return param_4;
        }
      }
    }
    else {
      FUN_006512e0(*(undefined4 *)(param_1 + 0x274),"TIFFReadEncodedTile",
                   s__lu__Tile_out_of_range__max__lu_00a06e24,param_2,*(uint *)(param_1 + 0xa8));
    }
  }
  return -1;
}

