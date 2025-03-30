package com.example.testmanagestate02

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.annotation.DrawableRes
import androidx.compose.foundation.ExperimentalFoundationApi
import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.size
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.foundation.shape.RoundedCornerShape
import androidx.compose.material3.Button
import androidx.compose.material3.ButtonDefaults
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.draw.clip
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.graphics.painter.Painter
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.text.TextStyle
import androidx.compose.ui.text.font.FontFamily
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import androidx.lifecycle.ViewModel
import com.example.testmanagestate02.ui.theme.TestManageState02Theme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            TestManageState02Theme {
               GreetingPreview()
            }
        }
    }
}


@Preview(showBackground = true)
@Composable
fun GreetingPreview() {
    TestManageState02Theme {
     //   CardDM(img = R.drawable.pic01, idx = 1)
      //  CardVIP()
        CustomEverything()
    }
}

class CustomState : ViewModel(){
    var _Click by mutableStateOf(false)

    fun setClick(newClick : Boolean){
        _Click = newClick
    }
}


data class getIndex(@DrawableRes val pic : Int,val idx : Int, val capy : Boolean)
fun getValue() = List(5) {i->
    val Pic = when(i){
        0 -> R.drawable.pic00
        1 -> R.drawable.pic01
        2 -> R.drawable.pic02
        3 -> R.drawable.pic03
        else -> { R.drawable.pic04 }
    }
    getIndex(pic = Pic, i, false)
}

@OptIn(ExperimentalFoundationApi::class)
@Composable
fun CustomEverything(MyState : CustomState = remember { CustomState() }) {
    val SrcImg: Int = R.drawable.ic_launcher_background
    val txt : String = "My Image I Choose"
    var MyImg by remember { mutableStateOf(SrcImg) }
    var MYtxt by remember { mutableStateOf(txt) }
    LazyColumn(modifier = Modifier.fillMaxSize()) {
        stickyHeader { CardVIP(selectImg = MyImg, txt = MYtxt) }
        items(getValue()) { i ->
            CardDM(img = i.pic, idx = i.idx, selectImg = {value->
                MyImg = value },{MYtxt = it}
            )
        }
    }
}

@Composable
fun CardDM(
    @DrawableRes img: Int,
    idx: Int,
    selectImg: (Int) -> Unit,
    selectTxt : (String) -> Unit
) {
    Column(modifier = Modifier.fillMaxSize()) {
        Row(verticalAlignment = Alignment.CenterVertically) {
            Image(
                painter = painterResource(id = img),
                contentDescription = null,
                modifier = Modifier
                    .clip(RoundedCornerShape(15.dp))
                    .size(175.dp)
            )
            Button(
                onClick = {
                             selectImg(img)
                    selectTxt("This is Image $idx")
                          },
                colors = ButtonDefaults.buttonColors(
                    containerColor = Color(0xFFAED6F1)
                ),
                modifier = Modifier.padding(start = 10.dp)
            ) {
                Text(text = "I Choose")
            }
        }
        Text(text = "This is Image $idx",
            modifier = Modifier.padding(start = 10.dp),
            style = TextStyle(
                fontWeight = FontWeight.Bold,
                fontFamily = FontFamily.Serif,
                color = Color(0xFFF2C678)
            )
        )
    }
}

@Composable
fun CardVIP(
   selectImg: Int,
   txt : String
) {
    Column(modifier = Modifier
        .fillMaxSize()
        .padding(bottom = 10.dp)
    ) {
//        val selectedImage = remember { mutableStateOf(selectImg) }
//        if (selectedImage.value != null) {
            Image(
                painter = painterResource(id = selectImg),
                contentDescription = null,
                modifier = Modifier
                    .clip(RoundedCornerShape(15.dp))
                    .size(175.dp)
            )
            Text(
                text = txt,
                modifier = Modifier.padding(start = 10.dp),
                style = TextStyle(
                    fontWeight = FontWeight.Bold,
                    fontFamily = FontFamily.Serif,
                    color = Color(0xFFF2C678)
                )
            )
    }
}