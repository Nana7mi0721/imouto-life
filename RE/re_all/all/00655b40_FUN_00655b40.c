
void FUN_00655b40(int param_1,ushort *param_2,ushort param_3)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  
  uVar3 = 0;
  uVar2 = 0;
  if (param_3 != 0) {
    while (uVar1 = *param_2, uVar3 <= uVar1) {
      uVar2 = uVar2 + 1;
      param_2 = param_2 + 0xc;
      uVar3 = uVar1 + 1;
      if (param_3 <= uVar2) {
        return;
      }
    }
    FUN_00653460(*(undefined4 *)(param_1 + 0x274),"TIFFReadDirectoryCheckOrder",
                 s_Invalid_TIFF_directory__tags_are_00a0a24c);
  }
  return;
}

