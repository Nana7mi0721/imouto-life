
bool FUN_0064bc60(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 local_4;
  
  piVar1 = param_1;
  if (param_1[0x11] == 0) {
    iVar2 = FUN_006507d0(0x1818);
    piVar1[0x11] = iVar2;
    if (iVar2 == 0) {
      FUN_006512e0(*(undefined4 *)(*piVar1 + 0x274),"initYCbCrConversion",
                   s_No_space_for_YCbCr_>RGB_conversi_00a06590);
      return false;
    }
  }
  FUN_00651280(*piVar1,0x211,&local_4);
  FUN_00651280(*piVar1,0x214,&param_1);
  iVar2 = FUN_00653210(piVar1[0x11],local_4,param_1);
  return -1 < iVar2;
}

