
void FUN_00681510(int *param_1,char *param_2,uint param_3,int param_4)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  char cVar4;
  char cVar5;
  int iVar6;
  
  if ((((param_3 < 0xc) || (*param_2 != 'A')) || (param_2[1] != 'd')) ||
     (((param_2[2] != 'o' || (param_2[3] != 'b')) || (param_2[4] != 'e')))) {
    *(undefined4 *)(*param_1 + 0x14) = 0x50;
    *(uint *)(*param_1 + 0x18) = param_3 + param_4;
    (**(code **)(*param_1 + 4))(param_1,1);
    return;
  }
  cVar1 = param_2[9];
  cVar2 = param_2[10];
  bVar3 = param_2[0xb];
  cVar4 = param_2[5];
  cVar5 = param_2[6];
  iVar6 = *param_1;
  *(uint *)(iVar6 + 0x1c) = (uint)CONCAT11(param_2[7],param_2[8]);
  *(uint *)(iVar6 + 0x18) = (uint)CONCAT11(cVar4,cVar5);
  *(uint *)(iVar6 + 0x20) = (uint)CONCAT11(cVar1,cVar2);
  *(uint *)(iVar6 + 0x24) = (uint)bVar3;
  *(undefined4 *)(*param_1 + 0x14) = 0x4e;
  (**(code **)(*param_1 + 4))(param_1,1);
  *(undefined1 *)(param_1 + 0x42) = 1;
  *(byte *)((int)param_1 + 0x109) = bVar3;
  return;
}

