
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_005a7a00(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = 0;
  if (DAT_00f3a04c == 0) {
    return 0;
  }
  do {
    if ((&DAT_00e804e8)[iVar1] != (&DAT_00a38e2c)[iVar1]) break;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 4);
  if (iVar1 == 4) {
    if (DAT_00e39a54 != 0) goto LAB_005a7b47;
    if (((((((DAT_00e804c0 == param_1[7]) && (DAT_00e804b4 == param_1[4])) &&
           (DAT_00e804b8 == param_1[5])) &&
          ((DAT_00e804bc == param_1[6] && (DAT_00e804b0 == param_1[3])))) &&
         ((DAT_00e804a4 == *param_1 &&
          ((DAT_00e804a8 == param_1[1] && (DAT_00e804ac == param_1[2])))))) &&
        (DAT_00e804e0 == param_1[0xf])) &&
       ((((DAT_00e804d4 == param_1[0xc] && (DAT_00e804d8 == param_1[0xd])) &&
         (DAT_00e804dc == param_1[0xe])) &&
        (((DAT_00e804d0 == param_1[0xb] && (DAT_00e804c4 == param_1[8])) &&
         ((DAT_00e804c8 == param_1[9] &&
          ((DAT_00e804cc == param_1[10] && (DAT_00e804e4 == param_1[0x10])))))))))) {
      return 0;
    }
  }
  else if (DAT_00e39a54 != 0) goto LAB_005a7b47;
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
LAB_005a7b47:
  piVar2 = param_1;
  piVar3 = &DAT_00e804a4;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar3 = *piVar2;
    piVar2 = piVar2 + 1;
    piVar3 = piVar3 + 1;
  }
  FUN_0056d420(&DAT_00e804e8,&DAT_00a38e2c,0x10);
  local_30 = *param_1;
  local_2c = param_1[1];
  local_28 = param_1[2];
  local_24 = param_1[3];
  local_20 = param_1[8];
  local_1c = param_1[9];
  local_18 = param_1[10];
  local_14 = param_1[0xb];
  local_10 = param_1[0x10];
  local_c = DAT_00e804e8;
  local_8 = DAT_00e804ec;
  local_4 = _DAT_00e804f0;
  FUN_0059cb80(&DAT_00ddb600,0,0,0xb,&local_30,3,1);
  FUN_0059cb80(&DAT_00ddb600,3,0,2,&local_30,3,1);
  FUN_005a2cb0();
  iVar1 = FUN_005d39f0(param_1);
  return -(uint)(iVar1 != 0);
}

