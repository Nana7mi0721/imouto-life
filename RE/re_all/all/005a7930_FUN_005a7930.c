
int FUN_005a7930(int param_1,int param_2)

{
  int iVar1;
  int local_4;
  
  if (DAT_00f3a04c == 0) {
    return 0;
  }
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  if (param_1 < 0x100) {
    (&DAT_00e798a0)[param_1] = param_2;
    if (param_2 == 1) {
      if (DAT_00e7989c < param_1) {
        DAT_00e7989c = param_1;
      }
    }
    else {
      iVar1 = param_1;
      if (DAT_00e7989c == param_1) {
        while ((DAT_00e7989c = iVar1, 0 < DAT_00e7989c && ((&DAT_00e798a0)[DAT_00e7989c] == 0))) {
          iVar1 = DAT_00e7989c + -1;
        }
      }
    }
    FUN_005a2cb0();
  }
  if ((DAT_00a37dc8 == 1) && (param_1 < 4)) {
    local_4 = param_2;
    FUN_0059cb80(&DAT_00ddb600,2,0,param_1 * 3 + 4,&local_4,1,1);
  }
  FUN_00597e70();
  iVar1 = FUN_005d3a50(param_1,param_2);
  return -(uint)(iVar1 != 0);
}

