
undefined4
FUN_00597260(undefined4 *param_1,undefined4 *param_2,uint param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  param_1[0x11a] = param_5;
  param_1[0x119] = param_4;
  puVar2 = param_2;
  puVar3 = param_1 + 3;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  param_1[0x118] = 0;
  (*(code *)param_2[1])(param_2[6],0,0,0);
  if ((param_3 & 1) == 0) {
    iVar1 = FUN_005968b0();
    if (iVar1 == 0) goto LAB_0059731d;
    (*(code *)param_2[1])(param_2[6],0,0,0);
  }
  if ((param_3 & 2) == 0) {
    iVar1 = FUN_005f78e0(param_1);
    if (iVar1 == 0) goto LAB_0059731d;
    (*(code *)param_2[1])(param_2[6],0,0,0);
  }
  if ((param_3 & 4) == 0) {
    iVar1 = FUN_005fa270(param_1);
    if (iVar1 == 0) goto LAB_0059731d;
    (*(code *)param_2[1])(param_2[6],0,0,0);
  }
  iVar1 = FUN_005dd200(param_1,param_2,param_3);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
LAB_0059731d:
  *param_1 = 0;
  param_1[1] = 0;
  iVar1 = FUN_0056e030(param_1[0x114],"..\\..\\..\\..\\Source\\Library\\Main\\DxSoundConvert.cpp",
                       0x89);
  param_1[0x113] = iVar1;
  if (iVar1 == 0) {
    FUN_00597060(param_1);
    return 0xffffffff;
  }
  param_1[0x115] = 0;
  param_1[0x116] = 0;
  param_1[0x117] = 0;
  *param_1 = 1;
  return 0;
}

