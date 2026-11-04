
void FUN_006bf3c0(short *param_1,undefined2 *param_2)

{
  int iVar1;
  undefined1 *puVar2;
  short *psVar3;
  undefined1 local_80 [2];
  undefined1 local_7e [126];
  
  FUN_006bf450(local_80,param_2);
  FUN_006bf500(local_7e,param_2 + 8);
  puVar2 = local_80;
  iVar1 = 8;
  psVar3 = param_1;
  do {
    FUN_006bf450(psVar3,puVar2);
    puVar2 = puVar2 + 0x10;
    psVar3 = psVar3 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = 0x40;
  do {
    *param_1 = (short)(*param_1 + 8 >> 4);
    iVar1 = iVar1 + -1;
    param_1 = param_1 + 1;
  } while (iVar1 != 0);
  param_2[8] = 0;
  param_2[1] = 0;
  *param_2 = 0;
  return;
}

