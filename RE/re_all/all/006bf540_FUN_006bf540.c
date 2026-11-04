
void FUN_006bf540(short *param_1,undefined2 *param_2)

{
  short *psVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 local_80 [2];
  undefined1 local_7e [2];
  undefined1 local_7c [2];
  undefined1 local_7a [122];
  
  FUN_006bf600(local_80,param_2);
  FUN_006bf730(local_7e,param_2 + 8);
  FUN_006bf450(local_7c,param_2 + 0x10);
  FUN_006bf500(local_7a,param_2 + 0x18);
  puVar3 = local_80;
  iVar2 = 8;
  psVar1 = param_1;
  do {
    FUN_006bf600(psVar1,puVar3);
    puVar3 = puVar3 + 0x10;
    psVar1 = psVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = 0x40;
  do {
    *param_1 = (short)(*param_1 + 8 >> 4);
    iVar2 = iVar2 + -1;
    param_1 = param_1 + 1;
  } while (iVar2 != 0);
  param_2[0x18] = 0;
  param_2[0x11] = 0;
  param_2[0x10] = 0;
  param_2[10] = 0;
  param_2[9] = 0;
  param_2[8] = 0;
  param_2[3] = 0;
  param_2[2] = 0;
  param_2[1] = 0;
  *param_2 = 0;
  return;
}

