
void FUN_006bf850(short *param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  short *psVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  undefined1 auStackY_118 [128];
  undefined1 local_80 [128];
  
  puVar5 = auStackY_118 + 0x88;
  puVar1 = local_80;
  iVar3 = 8;
  puVar4 = param_2;
  do {
    FUN_006bf8e0(puVar1,puVar4);
    puVar4 = puVar4 + 4;
    puVar1 = puVar1 + 2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar3 = 8;
  psVar2 = param_1;
  do {
    puVar5 = puVar5 + 0x10;
    FUN_006bf8e0(psVar2,puVar5);
    psVar2 = psVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar3 = 0x40;
  do {
    *param_1 = (short)(*param_1 + 8 >> 4);
    iVar3 = iVar3 + -1;
    param_1 = param_1 + 1;
  } while (iVar3 != 0);
  for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_2 = 0;
    param_2 = param_2 + 1;
  }
  return;
}

