
int * FUN_0068f530(int param_1,int param_2)

{
  byte *pbVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined1 *puVar6;
  
  piVar2 = (int *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x400);
  puVar6 = &DAT_00823530;
  piVar4 = piVar2;
  do {
    iVar3 = 0;
    piVar5 = piVar4;
    do {
      piVar4 = piVar5 + 1;
      pbVar1 = puVar6 + iVar3;
      iVar3 = iVar3 + 1;
      *piVar5 = (int)((uint)*pbVar1 * -0x1fe + 0xfe01) / (param_2 * 0x200 + -0x200);
      piVar5 = piVar4;
    } while (iVar3 < 0x10);
    puVar6 = puVar6 + 0x10;
  } while ((int)puVar6 < 0x823630);
  return piVar2;
}

