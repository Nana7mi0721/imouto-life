
undefined8 FUN_00652ae0(int param_1)

{
  uint uVar1;
  undefined8 uVar2;
  ushort local_8;
  short asStack_6 [3];
  
  if (*(short *)(param_1 + 0x7e) == 1) {
    if (((*(short *)(param_1 + 0x5a) == 6) && (*(short *)(param_1 + 0x62) == 3)) &&
       ((*(uint *)(param_1 + 0xc) & 0x4000) == 0)) {
      FUN_00651280(param_1,0x212,&local_8,asStack_6);
      if (((local_8 == 1) || (local_8 == 2)) || (local_8 == 4)) {
        if (((asStack_6[0] == 1) || (asStack_6[0] == 2)) || (asStack_6[0] == 4)) {
          uVar1 = (uint)local_8;
          if (*(uint *)(param_1 + 0x38) < -uVar1) {
            uVar1 = ((*(uint *)(param_1 + 0x38) - 1) + uVar1) / uVar1;
          }
          else {
            uVar1 = 0;
          }
          uVar2 = FUN_00650b30(param_1,uVar1,0,asStack_6[0] * local_8 + 2,0,"TIFFScanlineSize64");
          FUN_00650b30(param_1,uVar2,*(undefined2 *)(param_1 + 0x54),0,"TIFFScanlineSize64");
          uVar2 = __aullshr();
          uVar2 = __aulldiv(uVar2,asStack_6[0],0);
          return uVar2;
        }
      }
      FUN_006512e0(*(undefined4 *)(param_1 + 0x274),"TIFFScanlineSize64",
                   s_Invalid_YCbCr_subsampling_00a07028);
      return 0;
    }
    uVar2 = FUN_00650b30(param_1,*(undefined4 *)(param_1 + 0x38),0,*(undefined2 *)(param_1 + 0x62),0
                         ,"TIFFScanlineSize64");
    FUN_00650b30(param_1,uVar2,*(undefined2 *)(param_1 + 0x54),0,"TIFFScanlineSize64");
  }
  else {
    FUN_00650b30(param_1,*(undefined4 *)(param_1 + 0x38),0,*(undefined2 *)(param_1 + 0x54),0,
                 "TIFFScanlineSize64");
  }
  uVar2 = __aullshr();
  return uVar2;
}

