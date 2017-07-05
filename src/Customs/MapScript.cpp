#include "Customs/MapScript.h"
#include <stdio.h>
MapScript::MapScript(GameObject *owner) : Script(owner) {}

void MapScript::Start() {

  map = SceneManager::GetInstance()->GetScene("Gameplay")->GetGameObject("Map");

  mapPosition = map->GetPosition();
  this->mapSize_x = map->GetWidth();
  this->mapSize_y = map->GetHeight();
  this->proportion_x=0;
  this->proportion_y=0;

    //Do not remove the following lines or the zoom will bug
  CameraSystem::GetInstance()->SetAndMovePos_x(mapPosition->m_x*-1);
  CameraSystem::GetInstance()->SetAndMovePos_y(mapPosition->m_y*-1);
  this->mapSpeed=CameraSystem::GetInstance()->GetCameraSpeed();
  nakedMan = SceneManager::GetInstance()->GetScene("Gameplay")->GetGameObject("NakedMan");
  script = (NakedManScript *)nakedMan->GetComponent("NakedManScript");
  nakedManPosition = nakedMan->GetPosition();
   input = InputSystem::GetInstance();
   CreateWalls();

}

void MapScript::ComponentUpdate() {

   RenderWallsRects();


  if (input->GetKeyPressed(INPUT_P))
    shake=true;

 if (input->GetKeyPressed(INPUT_Z))
    CameraSystem::GetInstance()->Lock();


  if(InputSystem::GetInstance()->GetKeyUp(INPUT_DOWN) && CameraSystem::GetInstance()->currentZoom > -50){
        CameraSystem::GetInstance()->ZoomOut(GetOwner()->originalWidth/4 + 1,nakedMan,SceneManager::GetInstance()->GetCurrentScene());
         CameraSystem::GetInstance()->ZoomIn(1,nakedMan,SceneManager::GetInstance()->GetCurrentScene());
        CameraSystem::GetInstance()->currentZoom -=25;
    }

  if(InputSystem::GetInstance()->GetKeyUp(INPUT_UP) && CameraSystem::GetInstance()->currentZoom < 0){
       CameraSystem::GetInstance()->ZoomIn(GetOwner()->originalWidth/4 +1,nakedMan,SceneManager::GetInstance()->GetCurrentScene());
       CameraSystem::GetInstance()->ZoomOut(1,nakedMan,SceneManager::GetInstance()->GetCurrentScene());
       CameraSystem::GetInstance()->currentZoom +=25;
    }
}

void MapScript::FixedComponentUpdate() {

      if(shake){
        //CameraShake(intensity,duration in seconds)
        CameraSystem::GetInstance()->CameraShake(8,1,SceneManager::GetInstance()->GetCurrentScene());
        if(!CameraSystem::GetInstance()->IsShaking())
        shake=false;
      }

    }
void MapScript::RenderWallsRects(){

    for(int i=0;i<leftWallsAmmount;i++){
    SDL_Rect x = {leftWalls[i].m_x,leftWalls[i].m_y,leftWalls[i].m_w,leftWalls[i].m_h};
    GraphicsSystem::GetInstance()->DrawFillRectangle(&x, x.w,x.h, 255,0,0,100);
    }
    for(int j=0;j<rightWallsAmmount;j++){
     SDL_Rect x = {rightWalls[j].m_x,rightWalls[j].m_y,rightWalls[j].m_w,rightWalls[j].m_h};
        GraphicsSystem::GetInstance()->DrawFillRectangle(&x, x.w,x.h, 255,0,0,100);
    }
    for(int k=0;k<upWallsAmmount;k++){
    SDL_Rect x = {upWalls[k].m_x,upWalls[k].m_y,upWalls[k].m_w,upWalls[k].m_h};
    GraphicsSystem::GetInstance()->DrawFillRectangle(&x, x.w,x.h, 255,0,0,100);
    }
    for(int l=0;l<downWallsAmmount;l++){
     SDL_Rect x = {downWalls[l].m_x,downWalls[l].m_y,downWalls[l].m_w,downWalls[l].m_h};
     GraphicsSystem::GetInstance()->DrawFillRectangle(&x, x.w,x.h, 255,0,0,100);
    }



}

void MapScript::CreateWalls(){

downWalls[downWallsAmmount]={-3507,-2538,4364,75};
downWallsOriginal[downWallsAmmount]={-3507,-2538,4364,75};
downWallsAmmount++;

rightWalls[rightWallsAmmount]={826,-3798,67,945};
rightWallsOriginal[rightWallsAmmount]={826,-3798,67,945};
rightWallsAmmount++;

downWalls[downWallsAmmount]={857,-3831,1935,30};
downWallsOriginal[downWallsAmmount]={857,-3831,1935,30};
downWallsAmmount++;


leftWalls[leftWallsAmmount]={2801,-3800,30,945};
leftWallsOriginal[leftWallsAmmount]={2801,-3800,30,945};
leftWallsAmmount++;

upWalls[upWallsAmmount]={2465,-2855,360,30};
upWallsOriginal[upWallsAmmount]={2465,-2855,360,30};
upWallsAmmount++;

leftWalls[leftWallsAmmount]={2436,-2811,30,690};
leftWallsOriginal[leftWallsAmmount]={2436,-2811,30,690};
leftWallsAmmount++;

downWalls[downWallsAmmount]={2468,-2118,360,30};
downWallsOriginal[downWallsAmmount]={2468,-2118,360,30};
downWallsAmmount++;

leftWalls[leftWallsAmmount]={2791,-2086,30,285};
leftWallsOriginal[leftWallsAmmount]={2791,-2086,30,285};
leftWallsAmmount++;

upWalls[upWallsAmmount]={2656,-1801,135,30};
upWallsOriginal[upWallsAmmount]={2656,-1801,135,30};
upWallsAmmount++;

leftWalls[leftWallsAmmount]={2626,-1770,30,449};
leftWallsOriginal[leftWallsAmmount]={2626,-1770,30,449};
leftWallsAmmount++;

upWalls[upWallsAmmount]={2344,-1313,285,30};
upWallsOriginal[upWallsAmmount]={2344,-1313,285,30};
upWallsAmmount++;

rightWalls[rightWallsAmmount]={2314,-1572,30,259};
rightWallsOriginal[rightWallsAmmount]={2314,-1572,30,259};
rightWallsAmmount++;

upWalls[upWallsAmmount]={934,-1608, 1366,30};
upWallsOriginal[upWallsAmmount]={934,-1608, 1366,30};
upWallsAmmount++;

leftWalls[leftWallsAmmount]={897,-1574,30,224};
leftWallsOriginal[leftWallsAmmount]={897,-1574,30,224};
leftWallsAmmount++;

downWalls[downWallsAmmount]={933,-1349,1125,30};
downWallsOriginal[downWallsAmmount]={933,-1349,1125,30};
downWallsAmmount++;

leftWalls[leftWallsAmmount]={2058,-1318,30,375};
leftWallsOriginal[leftWallsAmmount]={2058,-1318,30,375  };
leftWallsAmmount++;

upWalls[upWallsAmmount]={933,-933,1125,30};
upWallsOriginal[upWallsAmmount]={933,-933,1125,30};
upWallsAmmount++;

leftWalls[leftWallsAmmount]={900,-903,30,540};
leftWallsOriginal[leftWallsAmmount]={900,-903,30,540};
leftWallsAmmount++;

upWalls[upWallsAmmount]={542,-360,360,30};
upWallsOriginal[upWallsAmmount]={542,-360,360,30};
upWallsAmmount++;

leftWalls[leftWallsAmmount]={514,-329,30,445};
leftWallsOriginal[leftWallsAmmount]={514,-329,30,445 };
leftWallsAmmount++;

upWalls[upWallsAmmount]={327,125, 183,30};
upWallsOriginal[upWallsAmmount]={327,125, 183,30};
upWallsAmmount++;

rightWalls[rightWallsAmmount]={297,-519,30,644};
rightWallsOriginal[rightWallsAmmount]={297,-519,30,644};
rightWallsAmmount++;

upWalls[upWallsAmmount]={-63,-548,360,30};
upWallsOriginal[upWallsAmmount]={-63,-548,360,30};
upWallsAmmount++;

rightWalls[rightWallsAmmount]={-85,-715,30,165};
rightWallsOriginal[rightWallsAmmount]={-85,-715,30,165};
rightWallsAmmount++;

upWalls[upWallsAmmount]={-710,-738,624,30};
upWallsOriginal[upWallsAmmount]={-710,-738,624,30};
upWallsAmmount++;

rightWalls[rightWallsAmmount]={-752,-1480,30,733};
rightWallsOriginal[rightWallsAmmount]={-752,-1480,30,733};
rightWallsAmmount++;

upWalls[upWallsAmmount]={-1214,-1513,476,30};
upWallsOriginal[upWallsAmmount]={-1214,-1513,476,30};
upWallsAmmount++;

rightWalls[rightWallsAmmount]={-1239,-2244,30,735};
rightWallsOriginal[rightWallsAmmount]={-1239,-2244,30,735};
rightWallsAmmount++;

upWalls[upWallsAmmount]={-1557,-2278, 317,30};
upWallsOriginal[upWallsAmmount]={-1557,-2278, 317,30};
upWallsAmmount++;

leftWalls[leftWallsAmmount]={-1590,-2247,30,986};
leftWallsOriginal[leftWallsAmmount]={-1590,-2247,30,986};
leftWallsAmmount++;

upWalls[upWallsAmmount]={-2173,-1257,591 ,30};
upWallsOriginal[upWallsAmmount]={-2173,-1257,591 ,30};
upWallsAmmount++;

rightWalls[rightWallsAmmount]={-2205,-2461,33,735};
rightWallsOriginal[rightWallsAmmount]={-1239,-2244,30,1200};
rightWallsAmmount++;

leftWalls[leftWallsAmmount]={-445,-2250,30,326};
leftWallsOriginal[leftWallsAmmount]={-445,-2250,30,326};
leftWallsAmmount++;

upWalls[upWallsAmmount]={-416,-2280,706,30};
upWallsOriginal[upWallsAmmount]={-416,-2280,706,30};
upWallsAmmount++;

rightWalls[rightWallsAmmount]={290,-2250,30,326};
rightWallsOriginal[rightWallsAmmount]={290,-2250,30,326};
rightWallsAmmount++;

downWalls[downWallsAmmount]={-416,-1927,706,30};
downWallsOriginal[downWallsAmmount]={-416,-1927,706,30};
downWallsAmmount++;

upWalls[upWallsAmmount]={543,-2278,135 ,30};
upWallsOriginal[upWallsAmmount]={543,-2278,135 ,30};
upWallsAmmount++;

downWalls[downWallsAmmount]={543,-2116,135,30};
downWallsOriginal[downWallsAmmount]={543,-2116,135,30};
downWallsAmmount++;

leftWalls[leftWallsAmmount]={513,-2250,30,134};
leftWallsOriginal[leftWallsAmmount]={513,-2250,30,135};
leftWallsAmmount++;

rightWalls[rightWallsAmmount]={679,-2250,30,134};
rightWallsOriginal[rightWallsAmmount]={679,-2251,30,135};
rightWallsAmmount++;

leftWalls[leftWallsAmmount]={-1014,-2058,30,417};
leftWallsOriginal[leftWallsAmmount]={-1014,-2058,30,417};
leftWallsAmmount++;

rightWalls[rightWallsAmmount]={-669,-2058,30,417};
rightWallsOriginal[rightWallsAmmount]={-669,-2058,30,417};
rightWallsAmmount++;

upWalls[upWallsAmmount]={-983,-2084, 313,29};
upWallsOriginal[upWallsAmmount]={-983,-2084, 313,29};
upWallsAmmount++;

downWalls[downWallsAmmount]={-983,-1640,313,29};
downWallsOriginal[downWallsAmmount]={-983,-1640,313,29};
downWallsAmmount++;

upWalls[upWallsAmmount]={894,-2852, 556,30};
upWallsOriginal[upWallsAmmount]={894,-2852, 556,30};
upWallsAmmount++;

rightWalls[rightWallsAmmount]={1441,-2824,30,705};
rightWallsOriginal[rightWallsAmmount]={1441,-2824,30,705};
rightWallsAmmount++;

leftWalls[leftWallsAmmount]={862,-2824,30,705};
leftWallsOriginal[leftWallsAmmount]={862,-2824,30,705};
leftWallsAmmount++;

downWalls[downWallsAmmount]={894,-2117,556,30};
downWallsOriginal[downWallsAmmount]={894,-2117,556,30};
downWallsAmmount++;

leftWalls[leftWallsAmmount]={1003,-1317,30,255};
leftWallsOriginal[leftWallsAmmount]={1003,-1317,30,255};
leftWallsAmmount++;

rightWalls[rightWallsAmmount]={1350,-1317,30,255};
rightWallsOriginal[rightWallsAmmount]={1350,-1317,30,255};
rightWallsAmmount++;

downWalls[downWallsAmmount]={1034,-1058,315,29};
downWallsOriginal[downWallsAmmount]={1034,-1058,315,29};
downWallsAmmount++;

upWalls[upWallsAmmount]={-631,-1700, 931,30};
upWallsOriginal[upWallsAmmount]={-631,-1700, 931,30};
upWallsAmmount++;

leftWalls[leftWallsAmmount]={-631,-1610,30,70};
leftWallsOriginal[leftWallsAmmount]={-631,-1610,30,70};
leftWallsAmmount++;

downWalls[downWallsAmmount]={-600,-1540,164,30};
downWallsOriginal[downWallsAmmount]={1034,-1058,315,29};
downWallsAmmount++;

upWalls[upWallsAmmount]={-720,-1409, 285,30};
upWallsOriginal[upWallsAmmount]={-720,-1409, 285,30};
upWallsAmmount++;

leftWalls[leftWallsAmmount]={-442,-1507, 30,105};
leftWallsOriginal[leftWallsAmmount]={-442,-1507, 30,105};
leftWallsAmmount++;

downWalls[downWallsAmmount]={-720,-1251,780,30};
downWallsOriginal[downWallsAmmount]={-720,-1251,780,30};
downWallsAmmount++;

leftWalls[leftWallsAmmount]={-60,-1221, 30,255};
leftWallsOriginal[leftWallsAmmount]={-60,-1221, 30,255};
leftWallsAmmount++;

downWalls[downWallsAmmount]={-30,-966,330,30};
downWallsOriginal[downWallsAmmount]={-30,-966,330,30};
downWallsAmmount++;

rightWalls[rightWallsAmmount]={292,-1673,30,706};
rightWallsOriginal[rightWallsAmmount]={292,-1673,30,706};
rightWallsAmmount++;

upWalls[upWallsAmmount]={548,-1894, 705,30};
upWallsOriginal[upWallsAmmount]={548,-1894, 705,30};
upWallsAmmount++;

leftWalls[leftWallsAmmount]={518,-1863, 30,323};
leftWallsOriginal[leftWallsAmmount]={518,-1863, 30,323};
leftWallsAmmount++;


downWalls[downWallsAmmount]={548,-1539,120,29};
downWallsOriginal[downWallsAmmount]={548,-1539,120,29};
downWallsAmmount++;

rightWalls[rightWallsAmmount]={677,-1704,30,163};
rightWallsOriginal[rightWallsAmmount]={677,-1704,30,163};
rightWallsAmmount++;

downWalls[downWallsAmmount]={707,-1734,257,30};
downWallsOriginal[downWallsAmmount]={707,-1734,257,30};
downWallsAmmount++;

downWalls[downWallsAmmount]={982,-1832,268,30};
downWallsOriginal[downWallsAmmount]={982,-1832,268,30};
downWallsAmmount++;

rightWalls[rightWallsAmmount]={1254,-1865,26,34};
rightWallsOriginal[rightWallsAmmount]={1254,-1865,26,34};
rightWallsAmmount++;

rightWalls[rightWallsAmmount]={969,-1800,30,70};
rightWallsOriginal[rightWallsAmmount]={969,-1800,30,70};
rightWallsAmmount++;

rightWalls[rightWallsAmmount]={-3526,-1260,30,1930};
rightWallsOriginal[rightWallsAmmount]={-3526,-1260,30,1930};
rightWallsAmmount++;

upWalls[upWallsAmmount]={-3498,670, 942,30};
upWallsOriginal[upWallsAmmount]={-3498,670, 942,30};
upWallsAmmount++;

leftWalls[leftWallsAmmount]={-2556,52, 30,615};
leftWallsOriginal[leftWallsAmmount]={-2556,52, 30,615};
leftWallsAmmount++;

downWalls[downWallsAmmount]={-3497,-1287,954,30};
downWallsOriginal[downWallsAmmount]={-3497,-1287,954,30};
downWallsAmmount++;

leftWalls[leftWallsAmmount]={-2556,-1250, 30,672};
leftWallsOriginal[leftWallsAmmount]={-2556,1250, 30,672};
leftWallsAmmount++;

downWalls[downWallsAmmount]={-2522,-583,135,30};
downWallsOriginal[downWallsAmmount]={-2522,-583,135,30};
downWallsAmmount++;

rightWalls[rightWallsAmmount]={-2394,-748,30,162};
rightWallsOriginal[rightWallsAmmount]={-2394,-748,30,162};
rightWallsAmmount++;

downWalls[downWallsAmmount]={-2364,-778,203,30};
downWallsOriginal[downWallsAmmount]={-2364,-778,203,30};
downWallsAmmount++;

leftWalls[leftWallsAmmount]={-2161,-742, 30,163};
leftWallsOriginal[leftWallsAmmount]={-2161,-742, 30,163};
leftWallsAmmount++;


downWalls[downWallsAmmount]={-2139,-578,166,30};
downWallsOriginal[downWallsAmmount]={-2364,-778,203,30};
downWallsAmmount++;

leftWalls[leftWallsAmmount]={-1975,-547, 30,734};
leftWallsOriginal[leftWallsAmmount]={-1975,-547, 30,734};
leftWallsAmmount++;

upWalls[upWallsAmmount]={-2518,27, 122,30};
upWallsOriginal[upWallsAmmount]={-2518,27, 122,30};
upWallsAmmount++;

rightWalls[rightWallsAmmount]={-2397,57,30,2758};
rightWallsOriginal[rightWallsAmmount]={-2397,57,30,2758};
rightWallsAmmount++;

downWalls[downWallsAmmount]={-1950,186,164,29};
downWallsOriginal[downWallsAmmount]={-1950,186,164,29};
downWallsAmmount++;

leftWalls[leftWallsAmmount]={-1786,215, 30,195};
leftWallsOriginal[leftWallsAmmount]={-1786,215, 30,195};
leftWallsAmmount++;

upWalls[upWallsAmmount]={-1951,410, 165,30};
upWallsOriginal[upWallsAmmount]={-1951,410, 165,30};
upWallsAmmount++;

leftWalls[leftWallsAmmount]={-1981,441, 30,1951};
leftWallsOriginal[leftWallsAmmount]={-1786,215, 30,1951};
leftWallsAmmount++;

downWalls[downWallsAmmount]={-1952,2393,42,30};
downWallsOriginal[downWallsAmmount]={-1952,2393,42,30};
downWallsAmmount++;

upWalls[upWallsAmmount]={-2365,2813,1860 ,30};
upWallsOriginal[upWallsAmmount]={-2365,2813,1860 ,30};
upWallsAmmount++;

leftWalls[leftWallsAmmount]={-1405,2515, 30,300};
leftWallsOriginal[leftWallsAmmount]={-1405,2515, 30,300};
leftWallsAmmount++;

downWalls[downWallsAmmount]={-1570,2490,167,30};
downWallsOriginal[downWallsAmmount]={-1570,2490,167,30};
downWallsAmmount++;

leftWalls[leftWallsAmmount]={-1593,1975, 30,514};
leftWallsOriginal[leftWallsAmmount]={-1593,1975, 30,514};
leftWallsAmmount++;

upWalls[upWallsAmmount]={-1563,1945, 352,30};
upWallsOriginal[upWallsAmmount]={-1563,1945, 352,30};
upWallsAmmount++;

rightWalls[rightWallsAmmount]={-1910,2136,30,254};
rightWallsOriginal[rightWallsAmmount]={-1910,2136,30,254};
rightWallsAmmount++;

downWalls[downWallsAmmount]={-1890,2106,75,30};
downWallsOriginal[downWallsAmmount]={-1890,2106,75,30};
downWallsAmmount++;

rightWalls[rightWallsAmmount]={-1820,1843,30,262};
rightWallsOriginal[rightWallsAmmount]={-1820,1843,30,262};
rightWallsAmmount++;

downWalls[downWallsAmmount]={-1792,1815,360,30};
downWallsOriginal[downWallsAmmount]={-1792,1815,360,30};
downWallsAmmount++;

upWalls[upWallsAmmount]={-1792,1655,360 ,30};
upWallsOriginal[upWallsAmmount]={-1792,1655,360 ,30};
upWallsAmmount++;

rightWalls[rightWallsAmmount]={-1432,1686,30,128};
rightWallsOriginal[rightWallsAmmount]={-1432,1686,30,128};
rightWallsAmmount++;

rightWalls[rightWallsAmmount]={-1815,597,30,1005};
rightWallsOriginal[rightWallsAmmount]={-1815,597,30,1005};
rightWallsAmmount++;

downWalls[downWallsAmmount]={-1787,567,160,30};
downWallsOriginal[downWallsAmmount]={-1787,567,160,30};
downWallsAmmount++;

rightWalls[rightWallsAmmount]={-1627,27,30,539};
rightWallsOriginal[rightWallsAmmount]={-1627,27,30,539};
rightWallsAmmount++;

upWalls[upWallsAmmount]={-1791,28,195 ,30};
upWallsOriginal[upWallsAmmount]={-1791,28,195 ,30};
upWallsAmmount++;

rightWalls[rightWallsAmmount]={-1816,-752,30,779};
rightWallsOriginal[rightWallsAmmount]={-1816,-752,30,779};
rightWallsAmmount++;

downWalls[downWallsAmmount]={-1791,-776,770,30};
downWallsOriginal[downWallsAmmount]={-1791,-776,770,30};
downWallsAmmount++;

leftWalls[leftWallsAmmount]={-1018,-746, 30,675};
leftWallsOriginal[leftWallsAmmount]={-1018,-746, 30,675};
leftWallsAmmount++;

upWalls[upWallsAmmount]={-1081,-66,60 ,30};
upWallsOriginal[upWallsAmmount]={-1081,-66,60 ,30};
upWallsAmmount++;

leftWalls[leftWallsAmmount]={-1111,-35, 30,222};
leftWallsOriginal[leftWallsAmmount]={-1111,-35, 30,222};
leftWallsAmmount++;

downWalls[downWallsAmmount]={-1081,188,60,30};
downWallsOriginal[downWallsAmmount]={-1081,188,60,30};
downWallsAmmount++;

leftWalls[leftWallsAmmount]={-1021,218, 30,60};
leftWallsOriginal[leftWallsAmmount]={-1021,218, 30,60};
leftWallsAmmount++;

downWalls[downWallsAmmount]={-990,278,359,30};
downWallsOriginal[downWallsAmmount]={-990,278,359,30};
downWallsAmmount++;

leftWalls[leftWallsAmmount]={-1596,-330, 30,308};
leftWallsOriginal[leftWallsAmmount]={-1596,-330, 30,308};
leftWallsAmmount++;

rightWalls[rightWallsAmmount]={-1334,-330,30,322};
rightWallsOriginal[rightWallsAmmount]={-1334,-330,30,322};
rightWallsAmmount++;

upWalls[upWallsAmmount]={-1558,-360,225 ,31};
upWallsOriginal[upWallsAmmount]={-1558,-360,225 ,31};
upWallsAmmount++;

downWalls[downWallsAmmount]={-1558,-5,225,30};
downWallsOriginal[downWallsAmmount]={-1558,-5,225,30};
downWallsAmmount++;

leftWalls[leftWallsAmmount]={-1213,1397, 31 ,548};
leftWallsOriginal[leftWallsAmmount]={-1213,1397, 31 ,548};
leftWallsAmmount++;

upWalls[upWallsAmmount]={-1181,1374,710,30};
upWallsOriginal[upWallsAmmount]={-1181,1374,710,30};
upWallsAmmount++;

leftWalls[leftWallsAmmount]={-1016,533, 30 ,840};
leftWallsOriginal[leftWallsAmmount]={-1016,533, 30 ,840};
leftWallsAmmount++;

upWalls[upWallsAmmount]={-985,503,307,30};
upWallsOriginal[upWallsAmmount]={-985,503,307,30};
upWallsAmmount++;

upWalls[upWallsAmmount]={-1473,605,330,30};
upWallsOriginal[upWallsAmmount]={-1473,605,330,30};
upWallsAmmount++;

downWalls[downWallsAmmount]={-1474,1145,330,30};
downWallsOriginal[downWallsAmmount]={-1474,1145,330,30};
downWallsAmmount++;

leftWalls[leftWallsAmmount]={-1498,636, 30 ,506};
leftWallsOriginal[leftWallsAmmount]={-1498,636, 30 ,506};
leftWallsAmmount++;

rightWalls[rightWallsAmmount]={-1143,636,30,508};
rightWallsOriginal[rightWallsAmmount]={-1143,636,30,508};
rightWallsAmmount++;


}

int MapScript::DetectWallCollision(GameObject* object){

//0 not colliding,1=left,2=right,3=up,4=down

 for(int i=0;i<leftWallsAmmount;i++)
 if(((leftWalls[i].m_x<= (object->GetPosition()->m_x + object->GetWidth())) && ((leftWalls[i].m_x + leftWalls[i].m_w)>=object->GetPosition()->m_x)) &&
 ((leftWalls[i].m_y <=(object->GetPosition()->m_y + object->GetHeight())) && ((leftWalls[i].m_y + leftWalls[i].m_h)>=object->GetPosition()->m_y))){

            Vector playerprevious_vec;
          playerprevious_vec.m_x = leftWalls[i].m_x - 1 - object->GetWidth();
          playerprevious_vec.m_y = object->GetPosition()->m_y;
          object->SetPosition(playerprevious_vec);


 }

for(int j=0;j<rightWallsAmmount;j++)
if(((rightWalls[j].m_x<= (object->GetPosition()->m_x + object->GetWidth())) && ((rightWalls[j].m_x + rightWalls[j].m_w)>=object->GetPosition()->m_x)) &&
((rightWalls[j].m_y <=(object->GetPosition()->m_y + object->GetHeight())) && ((rightWalls[j].m_y + rightWalls[j].m_h)>=object->GetPosition()->m_y))){

        Vector playerprevious_vec;
          playerprevious_vec.m_x = rightWalls[j].m_x + rightWalls[j].m_w +1;
          playerprevious_vec.m_y = object->GetPosition()->m_y;
          object->SetPosition(playerprevious_vec);


}

for(int k=0;k<upWallsAmmount;k++)
if(((upWalls[k].m_x<= (object->GetPosition()->m_x + object->GetWidth())) && ((upWalls[k].m_x + upWalls[k].m_w)>=object->GetPosition()->m_x)) &&
((upWalls[k].m_y <=(object->GetPosition()->m_y + object->GetHeight())) && ((upWalls[k].m_y + upWalls[k].m_h)>=object->GetPosition()->m_y))){


       Vector playerprevious_vec;
          playerprevious_vec.m_x = object->GetPosition()->m_x;
          playerprevious_vec.m_y = upWalls[k].m_y - 1 - object->GetHeight();
          object->SetPosition(playerprevious_vec);


}


for(int l=0;l<downWallsAmmount;l++)
if(((downWalls[l].m_x<= (object->GetPosition()->m_x + object->GetWidth())) && ((downWalls[l].m_x + downWalls[l].m_w)>=object->GetPosition()->m_x)) &&
((downWalls[l].m_y <=(object->GetPosition()->m_y + object->GetHeight())) && ((downWalls[l].m_y + downWalls[l].m_h)>=object->GetPosition()->m_y))){


               Vector playerprevious_vec;
                  playerprevious_vec.m_x = object->GetPosition()->m_x;
                  playerprevious_vec.m_y = downWalls[l].m_y + downWalls[l].m_h + 1;
                  object->SetPosition(playerprevious_vec);


}

return 0;

 }