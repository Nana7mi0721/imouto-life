
undefined8 FUN_00651670(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  longlong lVar4;
  ushort local_8;
  ushort auStack_6 [3];
  
  if (((*(int *)(param_1 + 0x48) != 0) && (*(int *)(param_1 + 0x44) != 0)) &&
     (*(int *)(param_1 + 0x4c) != 0)) {
    if (((*(short *)(param_1 + 0x7e) != 1) || (*(short *)(param_1 + 0x5a) != 6)) ||
       ((*(short *)(param_1 + 0x62) != 3 || ((*(uint *)(param_1 + 0xc) & 0x4000) != 0)))) {
      uVar3 = FUN_006515a0(param_1,"TIFFVTileSize64");
      uVar3 = FUN_00650b30(param_1,param_2,0,uVar3);
      return uVar3;
    }
    FUN_00651280(param_1,0x212,&local_8,auStack_6);
    if ((((local_8 == 1) || (local_8 == 2)) || (local_8 == 4)) &&
       (((auStack_6[0] == 1 || (auStack_6[0] == 2)) || (auStack_6[0] == 4)))) {
      uVar2 = (uint)local_8;
      if (*(uint *)(param_1 + 0x44) < -uVar2) {
        uVar2 = ((uVar2 - 1) + *(uint *)(param_1 + 0x44)) / uVar2;
      }
      else {
        uVar2 = 0;
      }
      uVar1 = (uint)auStack_6[0];
      if (param_2 < -uVar1) {
        uVar1 = ((uVar1 - 1) + param_2) / uVar1;
      }
      else {
        uVar1 = 0;
      }
      uVar3 = FUN_00650b30(param_1,uVar2,0,auStack_6[0] * local_8 + 2,0,"TIFFVTileSize64");
      uVar2 = FUN_00650b30(param_1,uVar3,*(undefined2 *)(param_1 + 0x54),0,"TIFFVTileSize64");
      if ((uVar2 & 7) == 0) {
        FUN_00650b30(param_1,uVar3,*(undefined2 *)(param_1 + 0x54),0,"TIFFVTileSize64");
        lVar4 = __aullshr();
      }
      else {
        FUN_00650b30(param_1,uVar3,*(undefined2 *)(param_1 + 0x54),0,"TIFFVTileSize64");
        lVar4 = __aullshr();
        lVar4 = lVar4 + 1;
      }
      uVar3 = FUN_00650b30(param_1,lVar4,uVar1,0,"TIFFVTileSize64");
      return uVar3;
    }
    FUN_006512e0(*(undefined4 *)(param_1 + 0x274),"TIFFVTileSize64",
                 s_Invalid_YCbCr_subsampling___dx_d_00a06ca0,local_8,auStack_6[0]);
  }
  return 0;
}

