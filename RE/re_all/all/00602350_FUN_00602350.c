
/* WARNING: Removing unreachable block (ram,0x0060239c) */
/* WARNING: Removing unreachable block (ram,0x006023aa) */

int FUN_00602350(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_ESI;
  int iStack_1c;
  int *piStack_18;
  undefined4 uStack_8;
  
  piVar1 = param_3;
  piStack_18 = param_3;
  iStack_1c = 0x602364;
  iVar2 = (**(code **)(*param_3 + 0x14))();
  if (iVar2 < 0) {
    return iVar2;
  }
  iStack_1c = (int)register0x00000010 + -0xc;
  param_2 = 0;
  iVar2 = 0;
  iVar3 = (**(code **)(*piVar1 + 0xc))(piVar1,1,&param_2);
  if (iVar3 == 0) {
    do {
      iVar3 = FUN_00602230(unaff_ESI,uStack_8);
      if ((((iVar3 < 0) && (-1 < iVar2)) && (iVar3 != -0x7fffbffb)) &&
         ((iVar3 != -0x7ff8ffa9 && (iVar3 != -0x7ffbfdd6)))) {
        iVar2 = iVar3;
      }
      FUN_00602330(uStack_8);
      if (iVar3 == 0) {
        return 0;
      }
      iVar3 = (**(code **)(*piVar1 + 0xc))(piVar1,1,&uStack_8,&iStack_1c);
    } while (iVar3 == 0);
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  return -0x7ffbfdf9;
}

