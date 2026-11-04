
void FUN_0064d5f0(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                 uint param_5,uint param_6,int param_7,int param_8,undefined1 *param_9,
                 undefined1 *param_10,undefined1 *param_11,undefined1 *param_12)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  int local_4;
  
  if (param_6 != 0) {
    local_4 = param_6;
    do {
      param_6 = param_5;
      puVar4 = param_12;
      if (7 < param_5) {
        puVar3 = param_2;
        param_12 = (undefined1 *)(param_5 >> 3);
        do {
          *puVar3 = CONCAT31(CONCAT21(CONCAT11(*puVar4,*param_11),*param_10),*param_9);
          puVar3[1] = CONCAT31(CONCAT21(CONCAT11(puVar4[1],param_11[1]),param_10[1]),param_9[1]);
          puVar3[2] = CONCAT31(CONCAT21(CONCAT11(puVar4[2],param_11[2]),param_10[2]),param_9[2]);
          puVar3[3] = CONCAT31(CONCAT21(CONCAT11(puVar4[3],param_11[3]),param_10[3]),param_9[3]);
          puVar3[4] = CONCAT31(CONCAT21(CONCAT11(puVar4[4],param_11[4]),param_10[4]),param_9[4]);
          puVar3[5] = CONCAT31(CONCAT21(CONCAT11(puVar4[5],param_11[5]),param_10[5]),param_9[5]);
          param_2 = puVar3 + 8;
          puVar3[6] = CONCAT31(CONCAT21(CONCAT11(puVar4[6],param_11[6]),param_10[6]),param_9[6]);
          puVar3[7] = CONCAT31(CONCAT21(CONCAT11(puVar4[7],param_11[7]),param_10[7]),param_9[7]);
          puVar4 = puVar4 + 8;
          param_11 = param_11 + 8;
          param_10 = param_10 + 8;
          param_9 = param_9 + 8;
          param_6 = param_6 - 8;
          param_12 = (undefined1 *)((int)param_12 - 1);
          puVar3 = param_2;
        } while (param_12 != (undefined1 *)0x0);
      }
      if (param_6 != 0) {
        puVar3 = param_2;
        puVar2 = param_2;
        switch(param_6) {
        case 7:
          uVar1 = *puVar4;
          puVar2 = param_2 + 1;
          puVar4 = puVar4 + 1;
          *param_2 = CONCAT31(CONCAT21(CONCAT11(uVar1,*param_11),*param_10),*param_9);
          param_11 = param_11 + 1;
          param_10 = param_10 + 1;
          param_9 = param_9 + 1;
        case 6:
          uVar1 = *puVar4;
          puVar3 = puVar2 + 1;
          puVar4 = puVar4 + 1;
          *puVar2 = CONCAT31(CONCAT21(CONCAT11(uVar1,*param_11),*param_10),*param_9);
          param_11 = param_11 + 1;
          param_10 = param_10 + 1;
          param_9 = param_9 + 1;
        case 5:
          uVar1 = *puVar4;
          param_2 = puVar3 + 1;
          puVar4 = puVar4 + 1;
          *puVar3 = CONCAT31(CONCAT21(CONCAT11(uVar1,*param_11),*param_10),*param_9);
          param_11 = param_11 + 1;
          param_10 = param_10 + 1;
          param_9 = param_9 + 1;
        case 4:
          uVar1 = *puVar4;
          puVar3 = param_2 + 1;
          puVar4 = puVar4 + 1;
          *param_2 = CONCAT31(CONCAT21(CONCAT11(uVar1,*param_11),*param_10),*param_9);
          param_11 = param_11 + 1;
          param_10 = param_10 + 1;
          param_9 = param_9 + 1;
        case 3:
          uVar1 = *puVar4;
          param_2 = puVar3 + 1;
          puVar4 = puVar4 + 1;
          *puVar3 = CONCAT31(CONCAT21(CONCAT11(uVar1,*param_11),*param_10),*param_9);
          param_11 = param_11 + 1;
          param_10 = param_10 + 1;
          param_9 = param_9 + 1;
        case 2:
          uVar1 = *puVar4;
          puVar3 = param_2 + 1;
          puVar4 = puVar4 + 1;
          *param_2 = CONCAT31(CONCAT21(CONCAT11(uVar1,*param_11),*param_10),*param_9);
          param_11 = param_11 + 1;
          param_10 = param_10 + 1;
          param_9 = param_9 + 1;
        case 1:
          uVar1 = *puVar4;
          param_2 = puVar3 + 1;
          puVar4 = puVar4 + 1;
          *puVar3 = CONCAT31(CONCAT21(CONCAT11(uVar1,*param_11),*param_10),*param_9);
          param_11 = param_11 + 1;
          param_10 = param_10 + 1;
          param_9 = param_9 + 1;
        }
      }
      param_9 = param_9 + param_7;
      param_10 = param_10 + param_7;
      param_11 = param_11 + param_7;
      param_2 = param_2 + param_8;
      param_12 = puVar4 + param_7;
      local_4 = local_4 + -1;
    } while (local_4 != 0);
  }
  return;
}

